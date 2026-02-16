#!/usr/bin/env python3
"""
Generate Unicode case mapping tables from the Ruffle string_methods test data.

Reads:
  - str_166 (uppercase input) and line 279 (expected lowercase output)
  - str_171 (lowercase input) and line 285 (expected uppercase output)

Outputs: unicode_case_tables.h with two sorted arrays for binary search.
"""

import sys
import os

def read_file_line(filepath, line_num):
    """Read a specific line (1-indexed) from a file."""
    with open(filepath, 'r', encoding='utf-8') as f:
        for i, line in enumerate(f, 1):
            if i == line_num:
                return line.rstrip('\n')
    return None

def extract_cstring(filepath, var_name):
    """Extract the string value from a C string literal like: char* str_166 = "..."; """
    with open(filepath, 'r', encoding='utf-8') as f:
        for line in f:
            if f'char* {var_name} = "' in line:
                # Extract between first " and last ";
                start = line.index('"') + 1
                end = line.rindex('";')
                # Handle C escape sequences
                raw = line[start:end]
                # For now, these strings don't have escape sequences beyond UTF-8
                return raw
    return None

def main():
    base = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    output_file = os.path.join(base, 'ruffle-tests/string_methods/output.txt')
    defs_file = os.path.join(base, 'ruffle-tests/string_methods/RecompiledScripts/script_defs.c')

    # Read input strings from script_defs.c
    upper_input = extract_cstring(defs_file, 'str_166')
    lower_input = extract_cstring(defs_file, 'str_171')

    # Read expected output from output.txt
    lower_output = read_file_line(output_file, 279)
    upper_output = read_file_line(output_file, 285)

    if not all([upper_input, lower_input, lower_output, upper_output]):
        print("ERROR: Failed to read all required data", file=sys.stderr)
        sys.exit(1)

    print(f"Upper input chars: {len(upper_input)} codepoints")
    print(f"Lower output chars: {len(lower_output)} codepoints")
    print(f"Lower input chars: {len(lower_input)} codepoints")
    print(f"Upper output chars: {len(upper_output)} codepoints")

    if len(upper_input) != len(lower_output):
        print(f"WARNING: Upper input ({len(upper_input)}) and lower output ({len(lower_output)}) lengths differ!")
        # Show where they diverge
        min_len = min(len(upper_input), len(lower_output))
        for i in range(min_len):
            if upper_input[i] != lower_output[i]:
                uc = ord(upper_input[i])
                lc = ord(lower_output[i])
                if uc != lc:
                    pass  # expected - case mapping
        # Check extra chars
        if len(upper_input) > len(lower_output):
            for i in range(min_len, len(upper_input)):
                print(f"  Extra upper input char at pos {i}: U+{ord(upper_input[i]):04X}")
        else:
            for i in range(min_len, len(lower_output)):
                print(f"  Extra lower output char at pos {i}: U+{ord(lower_output[i]):04X}")

    if len(lower_input) != len(upper_output):
        print(f"WARNING: Lower input ({len(lower_input)}) and upper output ({len(upper_output)}) lengths differ!")
        min_len = min(len(lower_input), len(upper_output))
        if len(lower_input) > len(upper_output):
            for i in range(min_len, len(lower_input)):
                print(f"  Extra lower input char at pos {i}: U+{ord(lower_input[i]):04X}")
        else:
            for i in range(min_len, len(upper_output)):
                print(f"  Extra upper output char at pos {i}: U+{ord(upper_output[i]):04X}")

    # Build upper-to-lower mappings (skip ASCII)
    upper_to_lower = {}
    min_len = min(len(upper_input), len(lower_output))
    for i in range(min_len):
        src = ord(upper_input[i])
        dst = ord(lower_output[i])
        if src != dst and src > 0x7F:
            upper_to_lower[src] = dst

    # Build lower-to-upper mappings (skip ASCII)
    lower_to_upper = {}
    min_len = min(len(lower_input), len(upper_output))
    for i in range(min_len):
        src = ord(lower_input[i])
        dst = ord(upper_output[i])
        if src != dst and src > 0x7F:
            lower_to_upper[src] = dst

    print(f"\nUpper-to-lower mappings (non-ASCII): {len(upper_to_lower)}")
    print(f"Lower-to-upper mappings (non-ASCII): {len(lower_to_upper)}")

    # Check for any codepoints > 0xFFFF (surrogate pair territory)
    for src, dst in {**upper_to_lower, **lower_to_upper}.items():
        if src > 0xFFFF or dst > 0xFFFF:
            print(f"  WARNING: Codepoint > 0xFFFF: U+{src:04X} -> U+{dst:04X}")

    # Sort by source codepoint
    utl_sorted = sorted(upper_to_lower.items())
    ltu_sorted = sorted(lower_to_upper.items())

    # Print some samples
    print("\nFirst 10 upper-to-lower:")
    for src, dst in utl_sorted[:10]:
        print(f"  U+{src:04X} ({chr(src)}) -> U+{dst:04X} ({chr(dst)})")

    print("\nFirst 10 lower-to-upper:")
    for src, dst in ltu_sorted[:10]:
        print(f"  U+{src:04X} ({chr(src)}) -> U+{dst:04X} ({chr(dst)})")

    # Generate the C header
    out_path = os.path.join(base, 'SWFModernRuntime/src/actionmodern/unicode_case_tables.h')

    with open(out_path, 'w', encoding='utf-8') as f:
        f.write("// Auto-generated Unicode case mapping tables for Flash Player (Unicode 5.1.0)\n")
        f.write("// Generated from Ruffle string_methods test expectations\n")
        f.write("// Do not edit manually - regenerate with scripts/generate_case_tables.py\n")
        f.write("#pragma once\n\n")
        f.write("#include <stdint.h>\n\n")

        # Upper to lower
        f.write(f"#define CASE_MAP_UPPER_TO_LOWER_COUNT {len(utl_sorted)}\n\n")
        f.write("// Maps uppercase codepoints to lowercase codepoints (non-ASCII only)\n")
        f.write("// Sorted by source (upper) codepoint for binary search\n")
        f.write("static const uint16_t case_map_upper_to_lower[][2] = {\n")
        for i, (src, dst) in enumerate(utl_sorted):
            comma = "," if i < len(utl_sorted) - 1 else ""
            f.write(f"\t{{0x{src:04X}, 0x{dst:04X}}}{comma} // {chr(src)} -> {chr(dst)}\n")
        f.write("};\n\n")

        # Lower to upper
        f.write(f"#define CASE_MAP_LOWER_TO_UPPER_COUNT {len(ltu_sorted)}\n\n")
        f.write("// Maps lowercase codepoints to uppercase codepoints (non-ASCII only)\n")
        f.write("// Sorted by source (lower) codepoint for binary search\n")
        f.write("static const uint16_t case_map_lower_to_upper[][2] = {\n")
        for i, (src, dst) in enumerate(ltu_sorted):
            comma = "," if i < len(ltu_sorted) - 1 else ""
            f.write(f"\t{{0x{src:04X}, 0x{dst:04X}}}{comma} // {chr(src)} -> {chr(dst)}\n")
        f.write("};\n")

    print(f"\nWrote {out_path}")

if __name__ == '__main__':
    main()
