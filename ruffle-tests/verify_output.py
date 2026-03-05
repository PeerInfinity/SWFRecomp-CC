#!/usr/bin/env python3
"""Verify SWFRecomp runtime output against Ruffle AVM1 expected output.

Pipeline for each test:
1. Run SWFRecomp to generate C code (if not already done)
2. Compile generated C with SWFModernRuntime in NO_GRAPHICS mode
3. Run the native binary, capture stdout
4. Filter out runtime boilerplate, keep only trace output
5. Compare against output.txt
"""

import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import time
from datetime import datetime, timezone
from pathlib import Path
from collections import Counter

RUFFLE_KEY_TO_FLASH = {
    # Control keys
    "Backspace": 8, "Tab": 9, "Enter": 13, "Return": 13,
    "Command": 15,
    "Shift": 16, "LeftShift": 16, "RightShift": 16,
    "Control": 17, "LeftControl": 17, "RightControl": 17,
    "Alt": 18, "LeftAlt": 18, "RightAlt": 18,
    "Pause": 19, "CapsLock": 20, "Escape": 27,
    # Navigation
    "Space": 32, "PageUp": 33, "PageDown": 34,
    "End": 35, "Home": 36,
    "Left": 37, "ArrowLeft": 37,
    "Up": 38, "ArrowUp": 38,
    "Right": 39, "ArrowRight": 39,
    "Down": 40, "ArrowDown": 40,
    "Insert": 45, "Delete": 46,
    # Numpad navigation (NumLock off) — logical key determines Flash code
    "NumpadLeft": 37, "NumpadUp": 38, "NumpadRight": 39, "NumpadDown": 40,
    "NumpadPageUp": 33, "NumpadPageDown": 34,
    "NumpadEnd": 35, "NumpadHome": 36,
    "NumpadInsert": 45, "NumpadDelete": 46,
    # Function keys (Ruffle AutomatedKey only defines F1-F9)
    "F1": 112, "F2": 113, "F3": 114, "F4": 115, "F5": 116,
    "F6": 117, "F7": 118, "F8": 119, "F9": 120,
    # Lock keys
    "NumLock": 144, "ScrollLock": 145,
    # Punctuation / symbols
    "Semicolon": 186, "Equal": 187, "Comma": 188, "Minus": 189,
    "Period": 190, "Slash": 191, "Backquote": 192,
    "LeftBracket": 219, "Backslash": 220, "RightBracket": 221,
    "Quote": 222,
}


# Numpad digit/operator chars → Flash numpad key codes
# Ruffle serializes Numpad(ch) as {"Numpad": "ch"} in input.json
NUMPAD_CHAR_TO_FLASH = {
    '0': 96, '1': 97, '2': 98, '3': 99, '4': 100,
    '5': 101, '6': 102, '7': 103, '8': 104, '9': 105,
    '*': 106, '+': 107, '-': 109, '.': 110, '/': 111,
}


def ruffle_key_to_flash_code(key):
    if isinstance(key, str):
        return RUFFLE_KEY_TO_FLASH.get(key, 0)
    elif isinstance(key, dict):
        if "Char" in key:
            c = key["Char"]
            return ord(c.upper()) if c.isalpha() else ord(c)
        if "Numpad" in key:
            return NUMPAD_CHAR_TO_FLASH.get(key["Numpad"], 0)
    return 0


def get_scale_factor(test_dir):
    """Parse scale_factor from test.toml viewport_dimensions, default 1.0."""
    toml_path = test_dir / "test.toml"
    if not toml_path.exists():
        return 1.0
    text = toml_path.read_text()
    m = re.search(r"scale_factor\s*=\s*([\d.]+)", text)
    return float(m.group(1)) if m else 1.0


def get_viewport_dimensions(test_dir):
    """Parse viewport width/height from test.toml, returns (width, height) or None."""
    toml_path = test_dir / "test.toml"
    if not toml_path.exists():
        return None
    text = toml_path.read_text()
    wm = re.search(r"viewport_dimensions\s*=\s*\{[^}]*width\s*=\s*(\d+)", text)
    hm = re.search(r"viewport_dimensions\s*=\s*\{[^}]*height\s*=\s*(\d+)", text)
    if wm and hm:
        return (int(wm.group(1)), int(hm.group(1)))
    return None


def preprocess_input_json(src, dst, scale_factor=1.0):
    """Convert input.json to simple line-based event format. Returns wait_count."""
    with open(src) as f:
        events = json.load(f)
    lines = []
    for evt in events:
        t = evt.get("type", "")
        if t == "Wait":
            lines.append("WAIT")
        elif t == "MouseMove":
            x, y = evt["pos"]
            lines.append(f"MOUSE_MOVE {x / scale_factor:.6f} {y / scale_factor:.6f}")
        elif t == "MouseDown":
            x, y = evt["pos"]
            btn = evt.get("btn", "Left")
            lines.append(f"MOUSE_DOWN_{btn.upper()} {x / scale_factor:.6f} {y / scale_factor:.6f}")
        elif t == "MouseUp":
            x, y = evt["pos"]
            btn = evt.get("btn", "Left")
            lines.append(f"MOUSE_UP_{btn.upper()} {x / scale_factor:.6f} {y / scale_factor:.6f}")
        elif t == "MouseWheel":
            # Ruffle uses exactly one of 'lines' or 'pixels'
            delta = evt.get('lines') or evt.get('pixels') or 0
            lines.append(f"MOUSE_WHEEL {delta}")
        elif t == "KeyDown":
            code = ruffle_key_to_flash_code(evt.get("key", 0))
            lines.append(f"KEY_DOWN {code}")
        elif t == "KeyUp":
            code = ruffle_key_to_flash_code(evt.get("key", 0))
            lines.append(f"KEY_UP {code}")
        elif t == "TextInput":
            cp_raw = evt.get("codepoint", "")
            cp = ord(cp_raw[0]) if cp_raw else 0
            lines.append(f"TEXT_INPUT {cp}")
        elif t == "TextControl":
            lines.append(f"TEXT_CONTROL {evt.get('code', 'Backspace')}")
        elif t == "FocusGained":
            lines.append("FOCUSGAINED")
        elif t == "SetClipboardText":
            lines.append(f"SET_CLIPBOARD_TEXT {evt.get('text', '')}")
        elif t == "FocusLost":
            lines.append("FOCUSLOST")
        # Skip ImePreedit, ImeCommit for now
    with open(dst, "w") as f:
        f.write("\n".join(lines) + "\n")
    return sum(1 for l in lines if l == "WAIT")


SCRIPT_DIR = Path(__file__).parent
PROJECT_ROOT = SCRIPT_DIR.parent
RECOMP_BIN = PROJECT_ROOT / "SWFRecomp" / "build" / "SWFRecomp"
RECOMP_CONFIG = SCRIPT_DIR / "_shared" / "config.toml"
SWFMODERN = PROJECT_ROOT / "SWFModernRuntime"
MAIN_C = PROJECT_ROOT / "SWFRecomp" / "wasm_wrappers" / "main.c"
DIFF_SCRIPT = PROJECT_ROOT / "scripts" / "diff_ruffle_results.py"

# JSON result files
RESULTS_FINAL = SCRIPT_DIR / "results.json"
RESULTS_PREVIOUS = SCRIPT_DIR / "results_previous.json"
RESULTS_CURRENT = SCRIPT_DIR / "results_current.json"

SKIP = {"_shared", "__framework__", "_investigation"}

# Lines to filter from runtime output
BOILERPLATE_PATTERNS = [
    re.compile(r"^SWF Runtime Loaded"),
    re.compile(r"^=== SWF Execution"),
    re.compile(r"^\[HEAP\]"),
    re.compile(r"^\[Frame \d+\]"),
    re.compile(r"^\[Tag\] ShowFrame"),
    re.compile(r"^No function for frame"),
    re.compile(r"^WASM SWF Runtime"),
    re.compile(r"^This is a recompiled"),
    re.compile(r"^Call runSWF"),
    re.compile(r"^Starting SWF execution"),
]


OUTPUT_CONTEXT_LINES = 50
OUTPUT_CONTEXT_BEFORE = 5


def snippet_around_mismatch(actual, expected, max_lines=OUTPUT_CONTEXT_LINES,
                            before=OUTPUT_CONTEXT_BEFORE):
    """Return (actual_snippet, expected_snippet) centered on the first mismatch.

    Shows `before` lines of matching context, then up to max_lines - before
    lines from the mismatch onward. Adds truncation notes if trimmed.
    """
    actual_lines = actual.split("\n")
    expected_lines = expected.split("\n")

    # Find first mismatching line
    first_diff = 0
    for i in range(min(len(actual_lines), len(expected_lines))):
        if actual_lines[i] != expected_lines[i]:
            first_diff = i
            break
    else:
        # All common lines match — mismatch is due to different lengths
        first_diff = min(len(actual_lines), len(expected_lines))

    start = max(0, first_diff - before)
    end_actual = min(len(actual_lines), start + max_lines)
    end_expected = min(len(expected_lines), start + max_lines)

    def format_snippet(lines, start, end, total):
        parts = []
        if start > 0:
            parts.append(f"... ({start} lines before) ...")
        parts.extend(lines[start:end])
        remaining = total - end
        if remaining > 0:
            parts.append(f"... ({remaining} lines after) ...")
        return "\n".join(parts)

    return (format_snippet(actual_lines, start, end_actual, len(actual_lines)),
            format_snippet(expected_lines, start, end_expected, len(expected_lines)))


def get_git_sha():
    """Get the current git commit SHA, or None."""
    try:
        result = subprocess.run(
            ["git", "rev-parse", "HEAD"],
            cwd=str(PROJECT_ROOT),
            capture_output=True, text=True, timeout=5,
        )
        if result.returncode == 0:
            return result.stdout.strip()
    except Exception:
        pass
    return None


def get_num_frames(test_dir, wait_count=0, has_input=False):
    """Parse num_frames (or num_ticks) from test.toml, default 1."""
    toml_path = test_dir / "test.toml"
    declared = 1
    if toml_path.exists():
        text = toml_path.read_text()
        m = re.search(r"num_frames\s*=\s*(\d+)", text)
        if m:
            declared = int(m.group(1))
        else:
            m = re.search(r"num_ticks\s*=\s*(\d+)", text)
            if m:
                declared = int(m.group(1))
    # With frame-first event delivery, the frame runs before events are pumped.
    # After the last Wait group's events fire, one more frame tick is needed to
    # process the resulting state changes (e.g. button transitions). So use +2
    # instead of +1 when input events are present.
    min_ticks = (wait_count + 2) if has_input else (wait_count + 1)
    return max(declared, min_ticks)


def get_epsilon(test_dir):
    """Parse [approximations] epsilon from test.toml, default 0 (exact match)."""
    toml_path = test_dir / "test.toml"
    if toml_path.exists():
        text = toml_path.read_text()
        m = re.search(r"epsilon\s*=\s*([0-9.]+)", text)
        if m:
            return float(m.group(1))
    return 0.0


def _lines_approx_equal(actual_line, expected_line, epsilon):
    """Check if two lines are approximately equal (for numeric values)."""
    if actual_line == expected_line:
        return True
    if epsilon <= 0:
        return False
    # Try to parse both as numbers and compare with epsilon
    try:
        a = float(actual_line)
        e = float(expected_line)
        return abs(a - e) <= epsilon
    except (ValueError, OverflowError):
        return False


def filter_output(raw_output):
    """Remove runtime boilerplate, return only trace lines."""
    lines = raw_output.split("\n")
    filtered = []
    for line in lines:
        if any(p.match(line) for p in BOILERPLATE_PATTERNS):
            continue
        filtered.append(line)

    # Strip leading/trailing blank lines
    while filtered and filtered[0].strip() == "":
        filtered.pop(0)
    while filtered and filtered[-1].strip() == "":
        filtered.pop()

    return "\n".join(filtered)


def find_child_swfs(test_dir):
    """Find child .swf files (non-test.swf) in a test directory."""
    children = []
    for f in sorted(test_dir.iterdir()):
        if f.suffix == ".swf" and f.name != "test.swf":
            children.append(f)
    return children


def recompile_child_swf(swf_path, output_dir):
    """Recompile a child SWF into output_dir. Returns True on success."""
    # Create a temp dir with the child SWF as test.swf
    with tempfile.TemporaryDirectory(prefix="swf_child_") as tmpdir:
        tmp = Path(tmpdir)
        shutil.copy2(swf_path, tmp / "test.swf")
        shutil.copy2(RECOMP_CONFIG, tmp / "config.toml")
        try:
            result = subprocess.run(
                ["bash", "-c", "ulimit -v 4194304; exec \"$@\"", "--",
                 str(RECOMP_BIN), str(RECOMP_CONFIG)],
                cwd=str(tmp),
                capture_output=True,
                text=True,
                timeout=30,
            )
            if result.returncode != 0:
                return False
        except subprocess.TimeoutExpired:
            return False

        # Copy generated files to output_dir
        for folder in ["RecompiledScripts", "RecompiledTags"]:
            src = tmp / folder
            dst = output_dir / folder
            if src.exists():
                dst.mkdir(exist_ok=True)
                for f in src.iterdir():
                    if f.suffix in (".c", ".h"):
                        shutil.copy2(f, dst)
    return True


def _sanitize_prefix(filename):
    """Convert a filename like 'target.swf' to a C-safe identifier prefix like 'target'."""
    name = filename.rsplit(".", 1)[0]  # strip extension
    name = re.sub(r'[^a-zA-Z0-9]', '_', name)
    # C identifiers can't start with a digit
    if name and name[0].isdigit():
        name = "m_" + name
    return name


def generate_child_movie_file(child_swf_name, child_recomp_dir, build_dir):
    """Generate a self-contained C file for a child SWF movie.

    Reads the recompiled C files from child_recomp_dir and generates a single
    movie_<prefix>.c file in build_dir that wraps all symbols with a unique prefix.
    Returns the prefix used, or None on failure.
    """
    prefix = _sanitize_prefix(child_swf_name)

    # Read the child's constants.h to extract SWF_VERSION and frame dimensions
    constants_h = child_recomp_dir / "RecompiledTags" / "constants.h"
    swf_version = 8
    frame_width = 550
    frame_height = 400
    frame_count_val = 1
    if constants_h.exists():
        text = constants_h.read_text()
        m = re.search(r"#define\s+SWF_VERSION\s+(\d+)", text)
        if m:
            swf_version = int(m.group(1))
        m = re.search(r"#define\s+FRAME_WIDTH\s+(\d+)", text)
        if m:
            frame_width = int(m.group(1))
        m = re.search(r"#define\s+FRAME_HEIGHT\s+(\d+)", text)
        if m:
            frame_height = int(m.group(1))

    # Read the child's out.h to extract FRAME_COUNT and script declarations
    out_h = child_recomp_dir / "RecompiledScripts" / "out.h"
    script_funcs = []
    if out_h.exists():
        text = out_h.read_text()
        m = re.search(r"#define\s+FRAME_COUNT\s+(\d+)", text)
        if m:
            frame_count_val = int(m.group(1))
        for m in re.finditer(r"void\s+([a-zA-Z_]\w+)\(", text):
            fname = m.group(1)
            if fname not in script_funcs:
                script_funcs.append(fname)

    # Read the child's script_decls.h for all user-defined functions
    # (func2_*, func_anonymous_*, func_* etc.)
    user_funcs = []  # list of (name, full_declaration_line)
    script_decls = child_recomp_dir / "RecompiledScripts" / "script_decls.h"
    if script_decls.exists():
        text = script_decls.read_text()
        # Match function declarations like:
        # ActionVar func2_getGlobal_0(SWFAppContext* ...)
        # ActionVar func_anonymous_0(SWFAppContext* ...)
        # void func_something(SWFAppContext* ...)
        for m in re.finditer(r'\b(func2?_[a-zA-Z_][a-zA-Z0-9_]*)\s*\(', text):
            fname = m.group(1)
            if fname not in user_funcs:
                user_funcs.append(fname)

    # Read the child's script_defs.c to get string definitions and function implementations
    script_defs_path = child_recomp_dir / "RecompiledScripts" / "script_defs.c"
    str_defs = []
    str_names = []  # all str_N identifiers (both pointer and buffer types)
    max_string_id = 0
    script_defs_source = ""
    if script_defs_path.exists():
        script_defs_source = script_defs_path.read_text()
        for m in re.finditer(r'char\*\s+(str_\d+)\s*=\s*(".*?")\s*;', script_defs_source):
            str_defs.append((m.group(1), m.group(2)))
        # Also find buffer-type strings: char str_15[17];
        for m in re.finditer(r'\b(str_\d+)\b', script_defs_source):
            if m.group(1) not in str_names:
                str_names.append(m.group(1))
        m = re.search(r"#define\s+MAX_STRING_ID\s+(\d+)", script_defs_source)
        if m:
            max_string_id = int(m.group(1))

    # Read the child's script_N.c files (exclude script_defs.c — handled above)
    script_sources = {}
    scripts_dir = child_recomp_dir / "RecompiledScripts"
    if scripts_dir.exists():
        for f in sorted(scripts_dir.iterdir()):
            if (f.name.startswith("script_") and f.suffix == ".c"
                    and f.name != "script_defs.c"):
                script_sources[f.name] = f.read_text()

    # Read the child's tagMain.c
    tag_main = child_recomp_dir / "RecompiledTags" / "tagMain.c"
    tag_main_text = ""
    if tag_main.exists():
        tag_main_text = tag_main.read_text()

    # Build a list of all symbols that need prefixing
    all_renames = {}  # old_name -> new_name
    for str_name in str_names:
        all_renames[str_name] = f'{prefix}_{str_name}'
    for str_name, _ in str_defs:
        all_renames[str_name] = f'{prefix}_{str_name}'
    for func_name in script_funcs:
        all_renames[func_name] = f'{prefix}_{func_name}'
    for func_name in user_funcs:
        all_renames[func_name] = f'{prefix}_{func_name}'
    # Detect sprite_N_frame_*, button_*, and clip_actions_* symbols in tagMain
    if tag_main_text:
        for m in re.finditer(r'\b(sprite_\d+_frame_(?:funcs|\d+))\b', tag_main_text):
            sym = m.group(1)
            if sym not in all_renames:
                all_renames[sym] = f'{prefix}_{sym}'
        for m in re.finditer(r'\b(button_\d+_\w+)\b', tag_main_text):
            sym = m.group(1)
            if sym not in all_renames:
                all_renames[sym] = f'{prefix}_{sym}'
        for m in re.finditer(r'\b(clip_actions_\d+)\b', tag_main_text):
            sym = m.group(1)
            if sym not in all_renames:
                all_renames[sym] = f'{prefix}_{sym}'

    # Build a single compiled regex for all renames (single-pass replacement)
    # Match known symbol prefixes and check against rename dict in callback
    if all_renames:
        _rename_pattern = re.compile(
            r'\b(str_\d+|script_\d+|func2?_\w+|button_\d+_\w+|clip_action(?:s)?_\d+|sprite_\d+_frame_\w+)\b')
        _renames = all_renames  # capture for closure

        def apply_renames(text):
            """Apply all symbol renames to a block of C code (single pass)."""
            def _repl(m):
                sym = m.group(1)
                return _renames.get(sym, sym)
            return _rename_pattern.sub(_repl, text)
    else:
        def apply_renames(text):
            return text

    # Generate the combined wrapper file
    lines = []
    lines.append(f"// Auto-generated movie wrapper for {child_swf_name}")
    lines.append(f"// Prefix: {prefix}_")
    lines.append("")
    lines.append("#include <recomp.h>")
    lines.append("#include <setjmp.h>")
    lines.append("#include <string.h>")
    lines.append("#include <stackvalue.h>")
    lines.append("#include <variables.h>")
    lines.append("#include <actionmodern/action.h>")
    lines.append("")

    # Forward declarations for all strings and functions
    ptr_str_names = {s for s, _ in str_defs}
    for str_name, _ in str_defs:
        lines.append(f"extern char* {prefix}_{str_name};")
    for str_name in str_names:
        if str_name not in ptr_str_names:
            lines.append(f"extern char {prefix}_{str_name}[];")
    for func_name in script_funcs:
        lines.append(f"void {prefix}_{func_name}(SWFAppContext* app_context);")
    for func_name in user_funcs:
        lines.append(f"// Forward decl: {prefix}_{func_name}")
    # Forward declarations for button and clip_actions arrays from tagMain
    if tag_main_text:
        for m in re.finditer(r'^frame_func\s+(button_\d+_state_funcs)\s*\[\]', tag_main_text, re.MULTILINE):
            lines.append(f"extern frame_func {prefix}_{m.group(1)}[];")
        for m in re.finditer(r'^ButtonAction\s+(button_\d+_actions)\s*\[\]', tag_main_text, re.MULTILINE):
            lines.append(f"extern ButtonAction {prefix}_{m.group(1)}[];")
        for m in re.finditer(r'^ClipAction\s+(clip_actions_\d+)\s*\[\]', tag_main_text, re.MULTILINE):
            lines.append(f"extern ClipAction {prefix}_{m.group(1)}[];")
    lines.append("")

    # Include script_defs.c content (string definitions + function implementations)
    if script_defs_source:
        modified = script_defs_source
        # Remove #include lines and #define MAX_STRING_ID
        modified = re.sub(r'#include\s+[<"].*?[>"]\s*\n', '', modified)
        modified = re.sub(r'#define\s+MAX_STRING_ID\s+\d+\s*\n?', '', modified)
        # Apply all symbol renames
        modified = apply_renames(modified)
        lines.append(modified)
    lines.append("")

    # Script function implementations
    for fname, source in script_sources.items():
        modified = source
        # Remove #include lines
        modified = re.sub(r'#include\s+[<"].*?[>"]\s*\n', '', modified)
        # Apply all symbol renames
        modified = apply_renames(modified)
        lines.append(modified)
        lines.append("")

    # Frame functions from tagMain.c
    if tag_main_text:
        modified = tag_main_text
        # Remove includes
        modified = re.sub(r'#include\s+[<"].*?[>"]\s*\n', '', modified)
        # Remove FrameLabelEntry typedef (already defined in runtime)
        modified = re.sub(
            r'// Frame labels.*?size_t frame_label_count = \d+;',
            '', modified, flags=re.DOTALL)
        # Prefix frame_N functions
        frame_funcs_in_tag = list(set(re.findall(r'\b(frame_\d+)\b', tag_main_text)))
        for ff in frame_funcs_in_tag:
            modified = re.sub(rf'\b{ff}\b', f'{prefix}_{ff}', modified)
        # Apply all symbol renames (str_N, script_N, func_*)
        modified = apply_renames(modified)
        # Rename frame_funcs array
        modified = modified.replace('frame_func frame_funcs[]', f'frame_func {prefix}_frame_funcs[]')
        # Rename frame_label_data and frame_label_count
        modified = re.sub(r'\bframe_label_data\b', f'{prefix}_frame_label_data', modified)
        modified = re.sub(r'\bframe_label_count\b', f'{prefix}_frame_label_count', modified)
        # Rename tagInit
        modified = modified.replace('void tagInit(', f'void {prefix}_tagInit(')
        # Rename initVarArray call's MAX_STRING_ID
        modified = re.sub(r'initVarArray\(MAX_STRING_ID\)', f'initVarArray({max_string_id})', modified)
        lines.append(modified)
        lines.append("")

    # Generate the movie entry struct access function
    lines.append(f"// Movie entry for {child_swf_name}")
    lines.append(f"#include <libswf/swf.h>")
    lines.append("")
    lines.append(f"MovieEntry {prefix}_movie_entry = {{")
    lines.append(f'    .filename = "{child_swf_name}",')
    lines.append(f"    .frame_funcs = {prefix}_frame_funcs,")
    lines.append(f"    .init_func = {prefix}_tagInit,")
    lines.append(f"    .swf_version = {swf_version},")
    lines.append(f"    .frame_count = {frame_count_val},")
    lines.append(f"    .stage_width = {frame_width},")
    lines.append(f"    .stage_height = {frame_height},")
    lines.append(f"}};")
    lines.append("")

    # Write the file
    out_path = build_dir / f"movie_{prefix}.c"
    out_path.write_text("\n".join(lines))
    return prefix


def generate_movie_registry(prefixes, build_dir):
    """Generate movie_registry.c that maps filenames to MovieEntry pointers."""
    lines = []
    lines.append("// Auto-generated movie registry for multi-SWF tests")
    lines.append("#include <libswf/swf.h>")
    lines.append("#include <string.h>")
    lines.append("")
    for prefix in prefixes:
        lines.append(f"extern MovieEntry {prefix}_movie_entry;")
    lines.append("")
    lines.append(f"static MovieEntry* g_movie_entries[] = {{")
    for prefix in prefixes:
        lines.append(f"    &{prefix}_movie_entry,")
    lines.append("    NULL")
    lines.append("};")
    lines.append("")
    lines.append("MovieEntry* findMovieEntry(const char* filename) {")
    lines.append("    for (int i = 0; g_movie_entries[i] != NULL; i++) {")
    lines.append("        if (strcmp(g_movie_entries[i]->filename, filename) == 0)")
    lines.append("            return g_movie_entries[i];")
    lines.append("    }")
    lines.append("    return NULL;")
    lines.append("}")
    lines.append("")

    out_path = build_dir / "movie_registry.c"
    out_path.write_text("\n".join(lines))


def find_data_files(test_dir):
    """Find data files (non-.swf, non-.fla, non-config) in a test directory.
    These are files like testvars.txt that loadVariables loads at runtime."""
    skip_names = {"test.swf", "test.fla", "test.toml", "test.as", "output.txt"}
    skip_suffixes = {".swf", ".fla", ".toml"}
    data_files = []
    for f in sorted(test_dir.iterdir()):
        if f.is_dir():
            continue
        if f.name in skip_names:
            continue
        if f.suffix in skip_suffixes:
            continue
        data_files.append(f)
    return data_files


def generate_data_registry(data_files, build_dir):
    """Generate data_registry.c that embeds data file contents as C strings."""
    lines = []
    lines.append("// Auto-generated data file registry for loadVariables tests")
    lines.append('#include <libswf/swf.h>')
    lines.append('#include <string.h>')
    lines.append("")

    var_names = []
    for df in data_files:
        content = df.read_bytes()
        var_name = "data_" + re.sub(r'[^a-zA-Z0-9]', '_', df.name)
        var_names.append((var_name, df.name, len(content)))
        # Emit as a C byte array to handle any content safely
        hex_bytes = ", ".join(f"0x{b:02x}" for b in content)
        lines.append(f"static const char {var_name}[] = {{ {hex_bytes}, 0x00 }};")
    lines.append("")

    lines.append("static DataFileEntry g_data_files[] = {")
    for var_name, filename, length in var_names:
        # Escape filename for C string
        escaped = filename.replace("\\", "\\\\").replace('"', '\\"')
        lines.append(f'    {{ "{escaped}", {var_name}, {length} }},')
    lines.append("    { NULL, NULL, 0 }")
    lines.append("};")
    lines.append("")

    lines.append("DataFileEntry* findDataFile(const char* filename) {")
    lines.append("    for (int i = 0; g_data_files[i].filename != NULL; i++) {")
    lines.append("        if (strcmp(g_data_files[i].filename, filename) == 0)")
    lines.append("            return &g_data_files[i];")
    lines.append("    }")
    lines.append("    return NULL;")
    lines.append("}")
    lines.append("")

    out_path = build_dir / "data_registry.c"
    out_path.write_text("\n".join(lines))


def recompile_swf(test_dir, force=False):
    """Run SWFRecomp on test.swf if not already done (or if forced)."""
    if not force and (test_dir / "RecompiledScripts").exists():
        return True

    # Remove old output if forcing
    if force:
        for d in ["RecompiledScripts", "RecompiledTags"]:
            p = test_dir / d
            if p.exists():
                shutil.rmtree(p)

    try:
        result = subprocess.run(
            ["bash", "-c", "ulimit -v 4194304; exec \"$@\"", "--",
             str(RECOMP_BIN), str(RECOMP_CONFIG)],
            cwd=str(test_dir),
            capture_output=True,
            text=True,
            timeout=30,
        )
        return result.returncode == 0
    except subprocess.TimeoutExpired:
        return False


def get_mock_date_time(test_dir):
    """Parse mock_date_time from test.toml if present."""
    toml_path = test_dir / "test.toml"
    if toml_path.exists():
        text = toml_path.read_text()
        m = re.search(r"mock_date_time\s*=\s*(\d+)", text)
        if m:
            return int(m.group(1))
    return None


def compile_native(test_dir, num_frames, build_dir):
    """Compile generated C code with runtime into native binary."""
    mem_dir = build_dir / "memory"
    mem_dir.mkdir(exist_ok=True)

    # Copy runtime sources
    for src in [
        "src/actionmodern/action.c",
        "src/actionmodern/variables.c",
        "src/actionmodern/object.c",
        "src/actionmodern/unicode_case_tables.h",
        "src/utils.c",
        "src/libswf/swf_core.c",
        "src/libswf/tag.c",
        "src/libswf/tag_stubs.c",
        "src/libswf/hit_test.c",
        "src/memory/heap.c",
    ]:
        shutil.copy2(SWFMODERN / src, build_dir)

    shutil.copy2(SWFMODERN / "lib/c-hashmap/map.c", build_dir)
    shutil.copy2(SWFMODERN / "lib/o1heap/o1heap.c", build_dir)
    shutil.copy2(SWFMODERN / "lib/o1heap/o1heap.h", build_dir)
    shutil.copy2(SWFMODERN / "include/memory/heap.h", mem_dir)
    shutil.copy2(MAIN_C, build_dir)

    # Copy generated files for main SWF
    for folder in ["RecompiledScripts", "RecompiledTags"]:
        src_dir = test_dir / folder
        if src_dir.exists():
            for f in src_dir.iterdir():
                if f.suffix in (".c", ".h"):
                    shutil.copy2(f, build_dir)

    # Handle child SWFs (multi-SWF tests like loadMovie)
    child_swfs = find_child_swfs(test_dir)
    child_prefixes = []
    has_children = len(child_swfs) > 0

    for child_swf in child_swfs:
        child_recomp_dir = build_dir / f"_child_{_sanitize_prefix(child_swf.name)}"
        child_recomp_dir.mkdir(exist_ok=True)
        if recompile_child_swf(child_swf, child_recomp_dir):
            prefix = generate_child_movie_file(
                child_swf.name, child_recomp_dir, build_dir)
            if prefix:
                child_prefixes.append(prefix)

    if has_children:
        generate_movie_registry(child_prefixes, build_dir)

    # Handle data files (loadVariables tests: testvars.txt, etc.)
    data_files = find_data_files(test_dir)
    has_data_files = len(data_files) > 0
    if has_data_files:
        generate_data_registry(data_files, build_dir)

    # Compile
    inc = SWFMODERN / "include"
    extra_defines = []
    mock_time = get_mock_date_time(test_dir)
    if mock_time is not None:
        extra_defines.append(f"-DMOCK_DATE_TIME={mock_time}LL")
    viewport = get_viewport_dimensions(test_dir)
    if viewport is not None:
        extra_defines.append(f"-DVIEWPORT_WIDTH={viewport[0]}")
        extra_defines.append(f"-DVIEWPORT_HEIGHT={viewport[1]}")
    if has_children:
        extra_defines.append("-DHAS_CHILD_MOVIES")
    if has_data_files:
        extra_defines.append("-DHAS_DATA_FILES")
    # Pass SWF file size for getBytesLoaded/getBytesTotal
    # Use the uncompressed size from the SWF header (bytes 4-7), not the file system size,
    # because Flash reports the uncompressed size for compressed (CWS/ZWS) SWFs.
    test_swf = test_dir / "test.swf"
    if test_swf.exists():
        import struct
        with open(test_swf, "rb") as swf_f:
            swf_header = swf_f.read(8)
        if len(swf_header) >= 8:
            swf_file_size = struct.unpack("<I", swf_header[4:8])[0]
        else:
            swf_file_size = test_swf.stat().st_size
        extra_defines.append(f"-DSWF_FILE_SIZE={swf_file_size}")
    # Pass movie URL matching Ruffle's VFS format (file:///test.swf)
    extra_defines.append('-DSWF_URL="file:///test.swf"')
    try:
        result = subprocess.run(
            [
                "gcc",
                *[str(f) for f in sorted(build_dir.glob("*.c"))],
                "-DNO_GRAPHICS",
                f"-DMAX_FRAMES={num_frames}",
                "-D_POSIX_C_SOURCE=200809L",
                *extra_defines,
                f"-I{build_dir}",
                f"-I{inc}",
                f"-I{inc}/actionmodern",
                f"-I{inc}/libswf",
                f"-I{inc}/memory",
                f"-I{SWFMODERN}/lib/c-hashmap",
                "-w",
                "-std=c17",
                "-O2",
                "-o",
                str(build_dir / "test_run"),
                "-lm",
            ],
            capture_output=True,
            text=True,
            timeout=60,
        )
        return result.returncode == 0, result.stderr
    except subprocess.TimeoutExpired:
        return False, "compilation timed out after 60 seconds"


def run_binary(build_dir, event_file=None):
    """Run the compiled binary and capture output."""
    cmd = [str(build_dir / "test_run")]
    if event_file is not None:
        cmd.append(str(event_file))
    try:
        result = subprocess.run(
            cmd,
            capture_output=True,
            timeout=10,
        )
        return result.stdout.decode("utf-8", errors="replace"), result.returncode
    except subprocess.TimeoutExpired:
        return None, -1


def compare_output(actual, expected, epsilon=0.0):
    """Compare filtered actual output with expected output.
    Returns (match, diff_summary, stats_dict)."""
    actual_lines = actual.split("\n")
    expected_lines = expected.rstrip("\n").split("\n")

    # Strip leading/trailing blank lines from both (filter_output strips actual,
    # but split() can re-introduce a trailing empty element; treat both the same)
    for lines in (actual_lines, expected_lines):
        while lines and lines[0].strip() == "":
            lines.pop(0)
        while lines and lines[-1].strip() == "":
            lines.pop()

    max_lines = max(len(actual_lines), len(expected_lines))
    matching = sum(
        1
        for i in range(max_lines)
        if _lines_approx_equal(
            actual_lines[i] if i < len(actual_lines) else "<missing>",
            expected_lines[i] if i < len(expected_lines) else "<missing>",
            epsilon,
        )
    )
    line_stats = {
        "actual_lines": len(actual_lines),
        "expected_lines": len(expected_lines),
        "matching_lines": matching,
    }

    if matching == max_lines:
        return True, "", line_stats

    # Generate a brief diff summary
    diff = []
    mismatches = 0
    for i in range(min(max_lines, 20)):
        a = actual_lines[i] if i < len(actual_lines) else "<missing>"
        e = expected_lines[i] if i < len(expected_lines) else "<missing>"
        if not _lines_approx_equal(a, e, epsilon):
            mismatches += 1
            if mismatches <= 3:
                diff.append(f"  line {i+1}: got {a!r}, expected {e!r}")

    total_mismatches = max_lines - matching
    summary = f"{total_mismatches} line(s) differ (actual={len(actual_lines)}, expected={len(expected_lines)})"
    if diff:
        summary += "\n" + "\n".join(diff)
    return False, summary, line_stats


def format_diff(actual, expected, context=3, epsilon=0.0):
    """Generate a unified-diff-style view showing mismatches with context."""
    actual_lines = actual.split("\n")
    expected_lines = expected.split("\n")
    max_lines = max(len(actual_lines), len(expected_lines))

    out = []
    in_context = False
    skipped = 0

    for i in range(max_lines):
        a = actual_lines[i] if i < len(actual_lines) else None
        e = expected_lines[i] if i < len(expected_lines) else None

        if _lines_approx_equal(a if a is not None else "", e if e is not None else "", epsilon):
            if in_context:
                skipped += 1
                if skipped <= context:
                    out.append(f"  {i+1:4d}  {a}")
                elif skipped == context + 1:
                    out.append(f"       ...")
            continue

        # Show context lines before this mismatch
        if not in_context or skipped > context:
            # Show leading context
            start = max(0, i - context)
            if start > 0 and not in_context:
                out.append(f"       ...")
            for j in range(start, i):
                line = actual_lines[j] if j < len(actual_lines) else ""
                if not in_context or j >= i - context:
                    out.append(f"  {j+1:4d}  {line}")

        in_context = True
        skipped = 0

        if e is not None:
            out.append(f"- {i+1:4d}  {e}")
        else:
            out.append(f"- {i+1:4d}  <end of expected>")
        if a is not None:
            out.append(f"+ {i+1:4d}  {a}")
        else:
            out.append(f"+ {i+1:4d}  <end of actual>")

    return "\n".join(out)


def build_report(test_results, stats, total, total_available, run_start):
    """Build a JSON-serializable results report dict."""
    total_duration = round(time.monotonic() - run_start, 2)
    return {
        "metadata": {
            "timestamp": datetime.now(timezone.utc).isoformat(),
            "git_sha": get_git_sha(),
            "duration_seconds": total_duration,
            "total_available": total_available,
        },
        "total": total,
        "pass": stats["pass"],
        "fail": total - stats["pass"],
        "pass_rate": round(100 * stats["pass"] / total, 1) if total else 0,
        "breakdown": {
            k: stats[k]
            for k in ["output_mismatch", "compile_fail", "recomp_fail",
                       "runtime_segfault", "runtime_error", "timeout"]
            if stats[k]
        },
        "tests": test_results,
    }


def write_json(report, path):
    """Write report dict to a JSON file."""
    with open(path, "w") as f:
        json.dump(report, f, indent=2)


def run_diff_comparison(new_path, partial=False):
    """Run diff_ruffle_results.py comparing previous results to new_path.

    Prints a one-line summary to stdout. Requires results_previous.json to exist.
    """
    if not RESULTS_PREVIOUS.exists():
        return
    if not DIFF_SCRIPT.exists():
        return

    cmd = [
        sys.executable, str(DIFF_SCRIPT),
        str(RESULTS_PREVIOUS), str(new_path),
        "--summary-only", "--no-write",
    ]
    if partial:
        cmd.append("--partial")

    try:
        result = subprocess.run(cmd, capture_output=True, text=True, timeout=10)
        if result.returncode == 0 and result.stdout.strip():
            print(f"  [diff] {result.stdout.strip()}")
    except Exception:
        pass


def parse_args():
    parser = argparse.ArgumentParser(
        description="Verify SWFRecomp runtime output against Ruffle AVM1 expected output.",
        formatter_class=argparse.RawDescriptionHelpFormatter,
        epilog="""\
examples:
  %(prog)s                          Run all tests
  %(prog)s --test=this_swf7         Run a single test
  %(prog)s --test=foo --test=bar   Run multiple tests
  %(prog)s --test=this_swf7 --diff  Show diff for a single test
  %(prog)s --recompile              Force SWF recompilation for all tests
  %(prog)s --diff --limit=50        Run first 50 tests, show diffs for failures
  %(prog)s --json=results.json      Write JSON report
  %(prog)s --shard=1/4              Run first quarter of tests (for CI)
""",
    )
    parser.add_argument(
        "--test", metavar="NAME", action="append",
        help="Run specific test(s) by name (repeatable, e.g. --test=foo --test=bar)")
    parser.add_argument(
        "-v", "--verbose", action="store_true",
        help="Print status for each test as it runs")
    parser.add_argument(
        "--diff", action="store_true",
        help="Show unified diff for each failing test")
    parser.add_argument(
        "--list-pass", action="store_true",
        help="List all passing test names")
    parser.add_argument(
        "--list-fail", action="store_true",
        help="List all failing test names with failure reason")
    parser.add_argument(
        "--recompile", action="store_true",
        help="Force SWF recompilation (delete and regenerate RecompiledScripts)")
    parser.add_argument(
        "--limit", type=int, metavar="N",
        help="Only run the first N tests")
    parser.add_argument(
        "--shard", metavar="I/N",
        help="Run shard I of N (1-based, for CI parallelism)")
    parser.add_argument(
        "--json", metavar="PATH",
        help="Write JSON results report to PATH")
    return parser.parse_args()


def main():
    args = parse_args()

    if not RECOMP_BIN.exists():
        print(f"Error: SWFRecomp not found at {RECOMP_BIN}")
        print(f"Build it first:  cd {PROJECT_ROOT}/SWFRecomp/build && cmake .. && make -j")
        sys.exit(1)

    # Determine test list
    if args.test:
        import fnmatch
        all_dirs = sorted(
            d.name for d in SCRIPT_DIR.iterdir()
            if d.is_dir() and d.name not in SKIP
            and (d / "test.swf").exists() and (d / "output.txt").exists()
        )
        tests = []
        for t in args.test:
            if '*' in t or '?' in t:
                matched = fnmatch.filter(all_dirs, t)
                if not matched:
                    print(f"Warning: no tests match pattern '{t}'")
                tests.extend(matched)
            else:
                test_dir = SCRIPT_DIR / t
                if not test_dir.is_dir():
                    print(f"Error: test directory not found: {test_dir}")
                    sys.exit(1)
                tests.append(t)
        tests = sorted(set(tests))
    else:
        tests = sorted(
            d.name
            for d in SCRIPT_DIR.iterdir()
            if d.is_dir()
            and d.name not in SKIP
            and (d / "test.swf").exists()
            and (d / "output.txt").exists()
        )

    total_available = len(tests)
    if args.limit:
        tests = tests[:args.limit]

    # Shard: divide test list into shard_total chunks, run chunk shard_idx (1-based)
    shard_idx = shard_total = None
    if args.shard:
        parts = args.shard.split("/")
        shard_idx = int(parts[0])
        shard_total = int(parts[1])
        chunk = len(tests) // shard_total
        rem = len(tests) % shard_total
        start = sum(chunk + (1 if j <= rem else 0) for j in range(1, shard_idx))
        count = chunk + (1 if shard_idx <= rem else 0)
        tests = tests[start:start + count]

    # Save previous results before starting
    if RESULTS_FINAL.exists() and not args.test:
        shutil.copy2(RESULTS_FINAL, RESULTS_PREVIOUS)

    run_start = time.monotonic()
    stats = Counter()
    pass_list = []
    fail_list = []
    fail_details = {}
    fail_diffs = {}
    test_results = []  # Per-test results for JSON output

    incremental = not args.test  # Write live results when running full suite

    def save_incremental():
        """Write current results to results_current.json and run diff."""
        if not incremental:
            return
        completed = len(test_results)
        report = build_report(test_results, stats, completed, total_available, run_start)
        write_json(report, RESULTS_CURRENT)
        run_diff_comparison(RESULTS_CURRENT, partial=True)

    for i, name in enumerate(tests):
        test_dir = SCRIPT_DIR / name
        epsilon = get_epsilon(test_dir)
        if args.verbose:
            print(f"[{i+1}/{len(tests)}] {name}...", end=" ", flush=True)

        test_start = time.monotonic()
        entry = {"test": name}

        # Step 1: Recompile SWF
        if not recompile_swf(test_dir, force=args.recompile):
            stats["recomp_fail"] += 1
            fail_list.append(name)
            fail_details[name] = "SWFRecomp failed"
            entry.update(status="recomp_fail", detail="SWFRecomp failed",
                         duration=round(time.monotonic() - test_start, 2))
            test_results.append(entry)
            if args.verbose:
                print("RECOMP_FAIL")
            save_incremental()
            continue

        # Step 2: Compile native
        with tempfile.TemporaryDirectory(prefix="swf_verify_") as tmpdir:
            build_dir = Path(tmpdir)
            input_json = test_dir / "input.json"
            event_file = None
            wait_count = 0
            if input_json.exists():
                scale_factor = get_scale_factor(test_dir)
                event_file_path = build_dir / "input_events.txt"
                wait_count = preprocess_input_json(input_json, event_file_path, scale_factor)
                event_file = event_file_path
            num_frames = get_num_frames(test_dir, wait_count, has_input=input_json.exists())
            entry["num_frames"] = num_frames
            ok, err = compile_native(test_dir, num_frames, build_dir)
            if not ok:
                stats["compile_fail"] += 1
                fail_list.append(name)
                # Categorize compile error
                if "error:" in err:
                    first_err = next(
                        (l for l in err.splitlines() if "error:" in l), err[:200]
                    )
                    detail = first_err.strip()[:200]
                else:
                    detail = err[:200]
                fail_details[name] = f"compile: {detail[:120]}"
                entry.update(status="compile_fail", detail=detail,
                             duration=round(time.monotonic() - test_start, 2))
                test_results.append(entry)
                if args.verbose:
                    print("COMPILE_FAIL")
                save_incremental()
                continue

            # Step 3: Run binary
            raw_output, rc = run_binary(build_dir, event_file=event_file)
            if raw_output is None:
                stats["timeout"] += 1
                fail_list.append(name)
                fail_details[name] = "runtime timeout"
                entry.update(status="timeout", detail="runtime timeout (>10s)",
                             duration=round(time.monotonic() - test_start, 2))
                test_results.append(entry)
                if args.verbose:
                    print("TIMEOUT")
                save_incremental()
                continue
            if rc != 0 and rc not in (-11, 139):
                crash_status = "runtime_error"
                crash_detail = f"exit code {rc}"
                stats["runtime_error"] += 1
            elif rc in (-11, 139):
                crash_status = "segfault"
                crash_detail = "SIGSEGV"
                stats["runtime_segfault"] += 1
            else:
                crash_status = None

            if crash_status is not None:
                fail_list.append(name)
                fail_details[name] = f"{crash_status} ({crash_detail})"
                entry.update(status=crash_status, detail=crash_detail,
                             duration=round(time.monotonic() - test_start, 2))
                # Still compare output even for crashing tests
                if raw_output and raw_output.strip():
                    crash_actual = filter_output(raw_output)
                    crash_expected = (test_dir / "output.txt").read_text().replace("\r\n", "\n").rstrip("\n")
                    crash_match, crash_diff, crash_line_stats = compare_output(crash_actual, crash_expected, epsilon)
                    entry["lines"] = crash_line_stats
                    if crash_match:
                        entry["detail"] += " (output matches)"
                    if args.diff:
                        fail_diffs[name] = format_diff(crash_actual, crash_expected, epsilon=epsilon)
                test_results.append(entry)
                if args.verbose:
                    line_info = ""
                    if "lines" in entry:
                        ls = entry["lines"]
                        line_info = f" [{ls.get('matched',0)}/{ls.get('expected',0)} lines]"
                    print(f"{crash_status.upper()}{line_info}")
                save_incremental()
                continue

        # Step 4: Filter and compare
        actual = filter_output(raw_output)
        expected = (test_dir / "output.txt").read_text().replace("\r\n", "\n").rstrip("\n")

        match, diff_summary, line_stats = compare_output(actual, expected, epsilon)
        entry["lines"] = line_stats
        entry["duration"] = round(time.monotonic() - test_start, 2)
        if match:
            stats["pass"] += 1
            pass_list.append(name)
            entry["status"] = "pass"
            test_results.append(entry)
            if args.verbose:
                print("PASS")
        else:
            stats["output_mismatch"] += 1
            fail_list.append(name)
            fail_details[name] = diff_summary
            if args.diff:
                fail_diffs[name] = format_diff(actual, expected, epsilon=epsilon)
            entry["status"] = "output_mismatch"
            entry["detail"] = diff_summary.split("\n")[0]  # first line only
            actual_snip, expected_snip = snippet_around_mismatch(actual, expected)
            entry["actual_output"] = actual_snip
            entry["expected_output"] = expected_snip
            test_results.append(entry)
            if args.verbose:
                print("MISMATCH")
        save_incremental()

    # Print results
    total = len(tests)
    print(f"\n{'='*60}")
    print(f"Total tests:     {total}")
    print(f"Pass:            {stats['pass']} ({100*stats['pass']/total:.1f}%)" if total else "")
    print(f"Fail:            {total - stats['pass']}")
    print()
    print("Failure breakdown:")
    for key in ["output_mismatch", "compile_fail", "recomp_fail", "runtime_segfault", "runtime_error", "timeout"]:
        if stats[key]:
            print(f"  {stats[key]:4d}  {key}")

    if args.list_pass:
        print(f"\nPassing tests ({len(pass_list)}):")
        for name in pass_list:
            print(f"  {name}")

    if args.list_fail:
        print(f"\nFailing tests ({len(fail_list)}):")
        for name in fail_list:
            detail = fail_details.get(name, "")
            print(f"  {name}: {detail}")

    if args.diff and fail_diffs:
        for name, diff_text in fail_diffs.items():
            print(f"\n--- {name} (expected vs actual) ---")
            print(diff_text)

    # Write final JSON results
    if args.json:
        report = build_report(test_results, stats, total, total_available, run_start)
        write_json(report, args.json)
        print(f"\nResults written to {args.json}")

        # Run final diff comparison (non-partial)
        if not args.test:
            print("\nFinal diff vs previous results:")
            run_diff_comparison(args.json, partial=False)


if __name__ == "__main__":
    main()
