#!/usr/bin/env python3
"""
Style checker and fixer for SWFRecomp repositories.

This script compares code style between upstream and local versions,
focusing on:
1. Blank line indentation (upstream preserves tabs on blank lines)
2. Trailing newlines at end of file
3. Tab vs space consistency

Usage:
    python check_style.py <upstream_file> <local_file> [--fix]
    python check_style.py --compare-repos <upstream_dir> <local_dir> [--fix]
"""

import argparse
import os
import sys
import subprocess
from pathlib import Path


def get_indent_level(line):
    """Count leading tabs in a line."""
    count = 0
    for char in line:
        if char == '\t':
            count += 1
        else:
            break
    return count


def analyze_blank_line_style(content):
    """Analyze how blank lines are indented in the file."""
    lines = content.split('\n')
    blank_lines_with_tabs = 0
    blank_lines_without_tabs = 0

    current_indent = 0
    for i, line in enumerate(lines):
        stripped = line.strip()
        if stripped:
            current_indent = get_indent_level(line)
        else:
            # Blank line
            if line.startswith('\t'):
                blank_lines_with_tabs += 1
            elif line == '':
                blank_lines_without_tabs += 1

    return {
        'with_tabs': blank_lines_with_tabs,
        'without_tabs': blank_lines_without_tabs,
        'style': 'tabs_on_blank' if blank_lines_with_tabs > blank_lines_without_tabs else 'no_tabs_on_blank'
    }


def fix_blank_line_indentation(content, preserve_tabs=True):
    """
    Fix blank line indentation to match the desired style.

    If preserve_tabs=True, add tabs to blank lines based on surrounding context.
    If preserve_tabs=False, remove tabs from blank lines.
    """
    lines = content.split('\n')
    result = []

    current_indent = 0
    brace_stack = []

    for i, line in enumerate(lines):
        stripped = line.strip()

        if stripped:
            # Track brace nesting for indent context
            for char in stripped:
                if char == '{':
                    brace_stack.append(current_indent)
                elif char == '}' and brace_stack:
                    brace_stack.pop()

            current_indent = get_indent_level(line)
            # Remove trailing whitespace from non-blank lines
            result.append(line.rstrip())
        else:
            # Blank line
            if preserve_tabs and current_indent > 0:
                # Add tabs matching current indent level
                result.append('\t' * current_indent)
            else:
                result.append('')

    return '\n'.join(result)


def check_trailing_newline(content):
    """Check if file ends with a newline."""
    return content.endswith('\n')


def compare_files(upstream_path, local_path):
    """Compare two files and report style differences."""
    try:
        with open(upstream_path, 'r') as f:
            upstream = f.read()
    except FileNotFoundError:
        return {'error': f'Upstream file not found: {upstream_path}'}

    try:
        with open(local_path, 'r') as f:
            local = f.read()
    except FileNotFoundError:
        return {'error': f'Local file not found: {local_path}'}

    upstream_style = analyze_blank_line_style(upstream)
    local_style = analyze_blank_line_style(local)

    upstream_trailing = check_trailing_newline(upstream)
    local_trailing = check_trailing_newline(local)

    differences = []

    if upstream_style['style'] != local_style['style']:
        differences.append(f"Blank line style differs: upstream={upstream_style['style']}, local={local_style['style']}")

    if upstream_trailing != local_trailing:
        differences.append(f"Trailing newline differs: upstream={upstream_trailing}, local={local_trailing}")

    return {
        'upstream_style': upstream_style,
        'local_style': local_style,
        'upstream_trailing_newline': upstream_trailing,
        'local_trailing_newline': local_trailing,
        'differences': differences
    }


def fix_file_to_match_upstream(upstream_path, local_path, dry_run=False):
    """Fix local file to match upstream's style."""
    try:
        with open(upstream_path, 'r') as f:
            upstream = f.read()
    except FileNotFoundError:
        print(f"Error: Upstream file not found: {upstream_path}")
        return False

    try:
        with open(local_path, 'r') as f:
            local = f.read()
    except FileNotFoundError:
        print(f"Error: Local file not found: {local_path}")
        return False

    upstream_style = analyze_blank_line_style(upstream)
    upstream_trailing = check_trailing_newline(upstream)

    # Fix blank line indentation
    preserve_tabs = upstream_style['style'] == 'tabs_on_blank'
    fixed = fix_blank_line_indentation(local, preserve_tabs)

    # Fix trailing newline
    if upstream_trailing and not fixed.endswith('\n'):
        fixed += '\n'
    elif not upstream_trailing and fixed.endswith('\n'):
        fixed = fixed.rstrip('\n')

    if fixed != local:
        if dry_run:
            print(f"Would fix: {local_path}")
        else:
            with open(local_path, 'w') as f:
                f.write(fixed)
            print(f"Fixed: {local_path}")
        return True

    return False


def get_git_files(repo_path, branch='HEAD'):
    """Get list of tracked files in a git repo."""
    result = subprocess.run(
        ['git', 'ls-tree', '-r', '--name-only', branch],
        cwd=repo_path,
        capture_output=True,
        text=True
    )
    if result.returncode != 0:
        return []
    return [f for f in result.stdout.strip().split('\n') if f]


def compare_repos(upstream_dir, local_dir, extensions=None, fix=False, upstream_branch='master'):
    """Compare all matching files between two repos."""
    if extensions is None:
        extensions = ['.cpp', '.hpp', '.c', '.h']

    upstream_files = set(get_git_files(upstream_dir, upstream_branch))
    local_files = set(get_git_files(local_dir, 'HEAD'))

    common_files = upstream_files & local_files

    results = {}
    for file_path in sorted(common_files):
        if not any(file_path.endswith(ext) for ext in extensions):
            continue

        upstream_full = os.path.join(upstream_dir, file_path)
        local_full = os.path.join(local_dir, file_path)

        # Use git show to get the upstream version
        result = subprocess.run(
            ['git', 'show', f'{upstream_branch}:{file_path}'],
            cwd=upstream_dir,
            capture_output=True,
            text=True
        )
        if result.returncode != 0:
            continue

        # Write to temp file for comparison
        import tempfile
        with tempfile.NamedTemporaryFile(mode='w', suffix=os.path.basename(file_path), delete=False) as tmp:
            tmp.write(result.stdout)
            tmp_path = tmp.name

        try:
            if fix:
                fix_file_to_match_upstream(tmp_path, local_full)
            else:
                comparison = compare_files(tmp_path, local_full)
                if comparison.get('differences'):
                    results[file_path] = comparison
        finally:
            os.unlink(tmp_path)

    return results


def fix_repo_against_upstream(repo_dir, upstream_branch='upstream/master', extensions=None, dry_run=False):
    """Fix all files in a repo to match upstream's style."""
    if extensions is None:
        extensions = ['.cpp', '.hpp', '.c', '.h']

    # Get list of changed files
    result = subprocess.run(
        ['git', 'diff', '--name-only', upstream_branch],
        cwd=repo_dir,
        capture_output=True,
        text=True
    )
    if result.returncode != 0:
        print(f"Error: Could not get diff against {upstream_branch}")
        return

    changed_files = [f for f in result.stdout.strip().split('\n') if f]

    fixed_count = 0
    for file_path in changed_files:
        if not any(file_path.endswith(ext) for ext in extensions):
            continue

        local_full = os.path.join(repo_dir, file_path)
        if not os.path.exists(local_full):
            continue

        # Get upstream version
        result = subprocess.run(
            ['git', 'show', f'{upstream_branch}:{file_path}'],
            cwd=repo_dir,
            capture_output=True,
            text=True
        )
        if result.returncode != 0:
            # File doesn't exist in upstream (new file)
            continue

        # Write to temp file
        import tempfile
        with tempfile.NamedTemporaryFile(mode='w', suffix=os.path.basename(file_path), delete=False) as tmp:
            tmp.write(result.stdout)
            tmp_path = tmp.name

        try:
            if fix_file_to_match_upstream(tmp_path, local_full, dry_run=dry_run):
                fixed_count += 1
        finally:
            os.unlink(tmp_path)

    print(f"\n{'Would fix' if dry_run else 'Fixed'} {fixed_count} files")


def main():
    parser = argparse.ArgumentParser(description='Check and fix code style to match upstream')
    parser.add_argument('--compare-repos', action='store_true', help='Compare entire repositories')
    parser.add_argument('--fix-repo', action='store_true', help='Fix all changed files in a repo against upstream')
    parser.add_argument('--fix', action='store_true', help='Fix style issues')
    parser.add_argument('--dry-run', action='store_true', help='Show what would be fixed without making changes')
    parser.add_argument('--upstream', default='upstream/master', help='Upstream branch to compare against (default: upstream/master)')
    parser.add_argument('paths', nargs='*', help='File or directory paths')

    args = parser.parse_args()

    if args.fix_repo:
        if len(args.paths) != 1:
            print("Usage: check_style.py --fix-repo <repo_dir> [--upstream <branch>] [--dry-run]")
            sys.exit(1)

        fix_repo_against_upstream(args.paths[0], upstream_branch=args.upstream, dry_run=args.dry_run)

    elif args.compare_repos:
        if len(args.paths) != 2:
            print("Usage: check_style.py --compare-repos <upstream_dir> <local_dir>")
            sys.exit(1)

        results = compare_repos(args.paths[0], args.paths[1], fix=args.fix)

        if not args.fix:
            for file_path, comparison in results.items():
                print(f"\n{file_path}:")
                for diff in comparison.get('differences', []):
                    print(f"  - {diff}")

    elif len(args.paths) == 2:
        if args.fix:
            fix_file_to_match_upstream(args.paths[0], args.paths[1], dry_run=args.dry_run)
        else:
            result = compare_files(args.paths[0], args.paths[1])
            print(f"Comparison result: {result}")

    else:
        parser.print_help()


if __name__ == '__main__':
    main()
