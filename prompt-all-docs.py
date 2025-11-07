#!/usr/bin/env python3
"""
Script to iterate through .md files from md-files.json and run prompt.py for each.
Takes optional parameters for start index and number of files to process.
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


def get_last_index():
    """Get the last processed index from the state file."""
    state_file = Path(__file__).parent / 'prompt-state.txt'

    if not state_file.exists():
        return -1

    try:
        with open(state_file, 'r') as f:
            content = f.read().strip()
            if content:
                return int(content)
            return -1
    except (ValueError, IOError):
        return -1


def save_last_index(index):
    """Save the last processed index to the state file."""
    state_file = Path(__file__).parent / 'prompt-state.txt'

    with open(state_file, 'w') as f:
        f.write(str(index))


def process_next_file(md_files, text_mode=False, prompt_mode=False):
    """Process the next file in sequential mode."""
    # Get the last processed index
    last_index = get_last_index()
    next_index = last_index + 1

    # Check if we've reached the end
    if next_index >= len(md_files):
        print(f"All {len(md_files)} files have been processed.", file=sys.stderr)
        print("To start over, delete prompt-state.txt or run with --reset-next", file=sys.stderr)
        return

    # Get the directory containing this script
    script_dir = Path(__file__).parent
    prompt_script = script_dir / 'prompt.py'

    if not prompt_script.exists():
        print(f"Error: prompt.py not found at {prompt_script}", file=sys.stderr)
        sys.exit(1)

    # Process the file
    md_file = md_files[next_index]

    try:
        # Build command with optional flags
        cmd = ['python3', str(prompt_script), md_file]
        if text_mode:
            cmd.append('-t')
        elif prompt_mode:
            cmd.append('-p')

        # Run prompt.py with the md file path
        result = subprocess.run(
            cmd,
            cwd=script_dir,
            check=False
        )

        if result.returncode != 0:
            print(f"Warning: prompt.py returned non-zero exit code {result.returncode}", file=sys.stderr)

        # Save the index after successful processing
        save_last_index(next_index)

    except KeyboardInterrupt:
        print("\nInterrupted by user", file=sys.stderr)
        print(f"Index {next_index} was not completed. Will retry on next run.", file=sys.stderr)
        sys.exit(130)
    except Exception as e:
        print(f"Error processing {md_file}: {e}", file=sys.stderr)
        sys.exit(1)


def process_files(md_files, start_index=0, count=None, text_mode=False, prompt_mode=False):
    """Process the .md files by running prompt.py for each."""
    # Determine end index
    if count is None:
        end_index = len(md_files)
    else:
        end_index = min(start_index + count, len(md_files))

    # Validate start index
    if start_index >= len(md_files):
        print(f"Error: Start index {start_index} is beyond the file list length ({len(md_files)})", file=sys.stderr)
        sys.exit(1)

    print(f"Processing files {start_index} to {end_index - 1} (out of {len(md_files)} total files)")
    print()

    # Get the directory containing this script
    script_dir = Path(__file__).parent
    prompt_script = script_dir / 'prompt.py'

    if not prompt_script.exists():
        print(f"Error: prompt.py not found at {prompt_script}", file=sys.stderr)
        sys.exit(1)

    # Process each file
    for i in range(start_index, end_index):
        md_file = md_files[i]
        print(f"[{i}/{len(md_files) - 1}] Processing: {md_file}")
        print("-" * 80)

        try:
            # Build command with optional flags
            cmd = ['python3', str(prompt_script), md_file]
            if text_mode:
                cmd.append('-t')
            elif prompt_mode:
                cmd.append('-p')

            # Run prompt.py with the md file path
            result = subprocess.run(
                cmd,
                cwd=script_dir,
                check=False
            )

            if result.returncode != 0:
                print(f"Warning: prompt.py returned non-zero exit code {result.returncode}", file=sys.stderr)

        except KeyboardInterrupt:
            print("\nInterrupted by user", file=sys.stderr)
            print(f"Stopped at index {i}")
            sys.exit(130)
        except Exception as e:
            print(f"Error processing {md_file}: {e}", file=sys.stderr)

        print()

    print(f"Finished processing {end_index - start_index} files")


def main():
    parser = argparse.ArgumentParser(description='Process .md files from md-files.json using prompt.py')
    parser.add_argument('-s', '--start', type=int, help='Index in the JSON file to start from (default: 0 in batch mode)')
    parser.add_argument('-c', '--count', type=int, help='Number of files to process before exiting (default: all remaining files in batch mode)')
    parser.add_argument('-t', '--text', action='store_true', help='Pass -t flag to prompt.py (output command text)')
    parser.add_argument('-p', '--prompt', action='store_true', help='Pass -p flag to prompt.py (output just prompt contents)')
    parser.add_argument('--next', action='store_true', help='Sequential mode: process just the next file, tracking state in prompt-state.txt')
    parser.add_argument('--reset-next', action='store_true', help='Reset the sequential state file and exit')

    args = parser.parse_args()

    # Handle reset-next flag
    if args.reset_next:
        state_file = Path(__file__).parent / 'prompt-state.txt'
        if state_file.exists():
            state_file.unlink()
            print("Reset prompt-state.txt - next run with --next will start from the beginning")
        else:
            print("No state file to reset")
        sys.exit(0)

    # Validate arguments
    if args.text and args.prompt:
        print("Error: Cannot use both -t and -p flags", file=sys.stderr)
        sys.exit(1)

    if args.next and (args.start is not None or args.count is not None):
        print("Error: Cannot use --next with -s/--start or -c/--count", file=sys.stderr)
        sys.exit(1)

    # Load the file list
    md_files = load_md_files()

    if not md_files:
        print("Warning: No .md files found in md-files.json")
        sys.exit(0)

    # Process in sequential mode or batch mode
    if args.next:
        process_next_file(md_files, args.text, args.prompt)
    else:
        # Batch mode
        start = args.start if args.start is not None else 0

        # Validate batch mode arguments
        if start < 0:
            print("Error: Start index must be non-negative", file=sys.stderr)
            sys.exit(1)

        if args.count is not None and args.count < 1:
            print("Error: Count must be at least 1", file=sys.stderr)
            sys.exit(1)

        process_files(md_files, start, args.count, args.text, args.prompt)


if __name__ == '__main__':
    main()
