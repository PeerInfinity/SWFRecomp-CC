#!/usr/bin/env python3
"""
Script to generate Claude CLI prompts for working on documentation files.
Takes a .md file path as parameter and generates the appropriate prompt.
"""

import argparse
import subprocess
import sys


def build_prompt(md_file_path):
    """Build the Claude prompt for the given markdown file."""
    prompt = f"""Please read this file and follow its instructions:
{md_file_path}"""
    return prompt


def build_command(prompt):
    """Build the full Claude CLI command."""
    # Escape the prompt for shell - replace newlines with \n and escape special characters
    escaped_prompt = prompt.replace('\n', '\\n').replace('"', '\\"').replace('$', '\\$').replace('`', '\\`')

    # Updated jq filter to handle both text and tool_use content
    command = f'claude -p "{escaped_prompt}" --dangerously-skip-permissions --output-format stream-json --verbose 2>/dev/null | jq -r \'select(.type == "assistant") | if .message.content[0].type == "text" then .message.content[0].text elif .message.content[0].type == "tool_use" then "[" + .message.content[0].name + "] " + (.message.content[0].input | tostring) else empty end\''

    return command


def main():
    parser = argparse.ArgumentParser(description='Generate Claude CLI prompts for documentation files')
    parser.add_argument('md_file', help='Path to the .md file (e.g., SWFRecompDocs/prompts/completed/opcode-bit-and-0x60.md)')
    parser.add_argument('-t', '--text', action='store_true', help='Output the command text instead of running it')
    parser.add_argument('-p', '--prompt', action='store_true', help='Output just the prompt contents')

    args = parser.parse_args()

    # Build prompt
    prompt = build_prompt(args.md_file)

    if args.prompt:
        # Output just the prompt contents
        print(prompt)
    elif args.text:
        # Output the command text for copy/paste
        command = build_command(prompt)
        print(command)
    else:
        # Execute the command
        command = build_command(prompt)
        try:
            subprocess.run(command, shell=True, check=False)
        except KeyboardInterrupt:
            print("\nInterrupted by user", file=sys.stderr)
            sys.exit(130)
        except Exception as e:
            print(f"Error executing command: {e}", file=sys.stderr)
            sys.exit(1)


if __name__ == '__main__':
    main()
