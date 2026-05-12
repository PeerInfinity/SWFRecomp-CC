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
import atexit
import json
import os
import re
import shutil
import subprocess
import sys
import tempfile
import time
import tomllib
from datetime import datetime, timezone
from pathlib import Path
from collections import Counter

# Optional PIL import for image comparisons
try:
    from PIL import Image
    HAS_PIL = True
except ImportError:
    HAS_PIL = False

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

# Map shifted/punctuation Char values to their physical key codes.
# Flash Key.getCode() returns physical key codes (like JS keyCode),
# not ASCII values. E.g., '"' is typed via Shift+Quote, so keyCode=222.
CHAR_TO_KEYCODE = {
    "'": 222, '"': 222,   # Quote key
    ';': 186, ':': 186,   # Semicolon key
    '=': 187, '+': 187,   # Equal key (but numpad + is 107)
    ',': 188, '<': 188,   # Comma key
    '-': 189, '_': 189,   # Minus key (but numpad - is 109)
    '.': 190, '>': 190,   # Period key (but numpad . is 110)
    '/': 191, '?': 191,   # Slash key (but numpad / is 111)
    '`': 192, '~': 192,   # Backquote key
    '[': 219, '{': 219,   # Left bracket key
    '\\': 220, '|': 220,  # Backslash key
    ']': 221, '}': 221,   # Right bracket key
    '!': 49,  '@': 50, '#': 51, '$': 52, '%': 53,  # Shift+1-5
    '^': 54, '&': 55, '*': 56, '(': 57, ')': 48,   # Shift+6-0
}


def ruffle_key_to_flash_code(key):
    if isinstance(key, str):
        return RUFFLE_KEY_TO_FLASH.get(key, 0)
    elif isinstance(key, dict):
        if "Char" in key:
            c = key["Char"]
            if c in CHAR_TO_KEYCODE:
                return CHAR_TO_KEYCODE[c]
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


def parse_image_comparisons(test_dir):
    """Parse [image_comparisons.NAME] sections from test.toml.

    Each comparison has:
      - tolerance (default 0): per-channel difference threshold
      - max_outliers (default 0): max channels allowed to exceed tolerance
      - trigger (default "last_frame"): when to capture ("last_frame", "fs_command", or int)
      - known_failure (default false): whether the comparison is expected to fail
      - checks: list of {tolerance, max_outliers} dicts (advanced mode)

    If both simple (tolerance/max_outliers) and advanced (checks) are specified,
    the simple values are used as a single check.

    Returns a dict of comparison_name -> {checks: [...], trigger: ..., known_failure: bool}
    or empty dict if no image comparisons are configured.
    """
    toml_path = test_dir / "test.toml"
    if not toml_path.exists():
        return {}

    with open(toml_path, "rb") as f:
        data = tomllib.load(f)

    ic_section = data.get("image_comparisons")
    if not ic_section or not isinstance(ic_section, dict):
        return {}

    result = {}
    for name, config in ic_section.items():
        if not isinstance(config, dict):
            continue

        known_failure = config.get("known_failure", False)

        # Parse trigger: default "last_frame", can be int or string
        trigger_raw = config.get("trigger", "last_frame")
        if isinstance(trigger_raw, int):
            trigger = ("specific_iteration", trigger_raw)
        elif isinstance(trigger_raw, str):
            if trigger_raw == "last_frame":
                trigger = ("last_frame",)
            elif trigger_raw == "fs_command":
                trigger = ("fs_command",)
            else:
                # Try parsing as int
                try:
                    trigger = ("specific_iteration", int(trigger_raw))
                except ValueError:
                    trigger = ("last_frame",)
        else:
            trigger = ("last_frame",)

        # Parse checks: either simple (tolerance/max_outliers at top level)
        # or advanced (list of check dicts under "checks" key)
        checks_raw = config.get("checks", [])
        has_simple = "tolerance" in config or "max_outliers" in config

        if has_simple and checks_raw:
            # Ruffle treats this as an error; we use simple values only
            checks = [{
                "tolerance": config.get("tolerance", 0),
                "max_outliers": config.get("max_outliers", 0),
            }]
        elif checks_raw:
            checks = []
            for c in checks_raw:
                if isinstance(c, dict):
                    checks.append({
                        "tolerance": c.get("tolerance", 0),
                        "max_outliers": c.get("max_outliers", 0),
                    })
            if not checks:
                checks = [{"tolerance": 0, "max_outliers": 0}]
        else:
            checks = [{
                "tolerance": config.get("tolerance", 0),
                "max_outliers": config.get("max_outliers", 0),
            }]

        result[name] = {
            "checks": checks,
            "trigger": trigger,
            "known_failure": known_failure,
        }

    return result


def compare_images(actual_path, expected_path, checks):
    """Compare two PNG images using Ruffle's per-pixel per-channel algorithm.

    Args:
        actual_path: Path to the actual (rendered) PNG image.
        expected_path: Path to the expected PNG image.
        checks: List of dicts with 'tolerance' (int, 0-255) and 'max_outliers' (int).
                Test passes if ANY check passes.

    Returns:
        (passed: bool, message: str, max_diff: int)

    Algorithm (matching Ruffle):
    1. Both images are converted to RGBA.
    2. Dimensions must match exactly.
    3. Per-pixel, per-channel absolute difference is computed (4 channels: R, G, B, A).
    4. For each check: count how many individual channels exceed the tolerance.
       If the count <= max_outliers, the check passes.
    5. The test passes if any check passes.
    6. max_diff is the maximum single-channel difference across all pixels.
    """
    if not HAS_PIL:
        return False, "Pillow not installed, skipping image comparison", 0

    actual_path = Path(actual_path)
    expected_path = Path(expected_path)

    if not actual_path.exists():
        return False, f"Actual image not found: {actual_path}", 0
    if not expected_path.exists():
        return False, f"Expected image not found: {expected_path}", 0

    try:
        actual_img = Image.open(actual_path).convert("RGBA")
        expected_img = Image.open(expected_path).convert("RGBA")
    except Exception as e:
        return False, f"Failed to open image: {e}", 0

    # Check dimensions
    if actual_img.size != expected_img.size:
        return (False,
                f"Image size mismatch: actual {actual_img.size[0]}x{actual_img.size[1]}, "
                f"expected {expected_img.size[0]}x{expected_img.size[1]}",
                0)

    # Compute per-pixel per-channel absolute difference
    actual_data = actual_img.tobytes()
    expected_data = expected_img.tobytes()

    # difference_data: one byte per channel (RGBA), abs diff
    num_pixels = actual_img.size[0] * actual_img.size[1]
    difference_data = bytearray(num_pixels * 4)
    max_diff = 0
    for i in range(num_pixels * 4):
        d = abs(actual_data[i] - expected_data[i])
        difference_data[i] = d
        if d > max_diff:
            max_diff = d

    # Save the difference image whenever there's something to look at.
    # Skips strict passes (max_diff=0 → an all-black PNG that adds no
    # signal); tolerance passes still get a diff written so reviewers
    # can see which pixels drift even on a "pass". Best-effort: a failed
    # save doesn't fail the check itself.
    if max_diff > 0:
        diff_image_path = actual_path.parent / (actual_path.stem + ".difference.png")
        try:
            # Copy into a separate buffer so the outlier counter below still
            # sees the true per-channel alpha diff. Set alpha=0 on pixels
            # where every channel matches (so matching regions show through
            # transparently in viewers that composite onto a background),
            # and alpha=255 where any channel differs (so mismatches are
            # opaque and clearly visible).
            png_bytes = bytearray(difference_data)
            for px in range(num_pixels):
                base = px * 4
                if png_bytes[base] | png_bytes[base + 1] | png_bytes[base + 2] | png_bytes[base + 3]:
                    png_bytes[base + 3] = 255
                else:
                    png_bytes[base + 3] = 0
            diff_img = Image.frombytes("RGBA", actual_img.size, bytes(png_bytes))
            # Brighten RGB channels (×4 clamped) without touching alpha.
            r, g, b, a = diff_img.split()
            lut = bytes(min(x * 4, 255) for x in range(256))
            r = r.point(lut); g = g.point(lut); b = b.point(lut)
            diff_img = Image.merge("RGBA", (r, g, b, a))
            diff_img.save(str(diff_image_path))
        except Exception:
            pass

    # Try each check -- test passes if ANY check passes (Ruffle semantics)
    best_outliers = None
    best_max_outliers = None
    for check in checks:
        tolerance = check["tolerance"]
        max_outliers = check["max_outliers"]

        # Count outlier channels (each channel independently, matching Ruffle)
        outliers = 0
        for px in range(num_pixels):
            base = px * 4
            outliers += (difference_data[base] > tolerance)
            outliers += (difference_data[base + 1] > tolerance)
            outliers += (difference_data[base + 2] > tolerance)
            outliers += (difference_data[base + 3] > tolerance)

        if outliers <= max_outliers:
            return (True,
                    f"Image check passed: {outliers} outliers (limit {max_outliers}), "
                    f"max difference {max_diff}",
                    max_diff)

        # Track the closest failing check for the error message
        if best_outliers is None or outliers < best_outliers:
            best_outliers = outliers
            best_max_outliers = max_outliers

    # All checks failed. The difference image was already saved above
    # (or skipped, if max_diff was 0 — which can't happen on a fail).
    return (False,
            f"Image comparison failed: {best_outliers} outliers exceed limit of "
            f"{best_max_outliers}, max difference {max_diff}",
            max_diff)


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
        elif t == "ImePreedit":
            text = evt.get("text", "")
            cursor = evt.get("cursor")
            cursor_from = cursor[0] if cursor else -1
            cursor_to = cursor[1] if cursor else -1
            lines.append(f"IME_PREEDIT {cursor_from} {cursor_to} {text}")
        elif t == "ImeCommit":
            text = evt.get("text", "")
            lines.append(f"IME_COMMIT {text}")
        # Skip unknown event types
    with open(dst, "w") as f:
        f.write("\n".join(lines) + "\n")
    return sum(1 for l in lines if l == "WAIT")


SCRIPT_DIR = Path(__file__).parent
PROJECT_ROOT = SCRIPT_DIR.parent
TESTS_DIR = SCRIPT_DIR / "tests" / "swfs" / "avm1"
RECOMP_BIN = PROJECT_ROOT / "SWFRecomp" / "build" / "SWFRecomp"
RECOMP_CONFIG = SCRIPT_DIR / "_shared" / "config.toml"
SWFMODERN = PROJECT_ROOT / "SWFModernRuntime"
MAIN_C = PROJECT_ROOT / "SWFRecomp" / "wasm_wrappers" / "main.c"
DIFF_SCRIPT = PROJECT_ROOT / "scripts" / "diff_ruffle_results.py"
DAWN_INSTALL = Path(os.environ.get("DAWN_INSTALL", PROJECT_ROOT.parent / "dawn-install"))
STB_DIR = PROJECT_ROOT / "SWFRecomp" / "lib" / "stb"
# Ruffle upstream test assets (expected PNGs live here)
RUFFLE_UPSTREAM = Path.home() / "CC" / "ruffle" / "tests" / "tests" / "swfs" / "avm1"

# JSON result files (re-derived from TESTS_DIR in main() when --tests-dir is used)
RESULTS_DIR = TESTS_DIR / "_results"
RESULTS_FINAL = RESULTS_DIR / "results.json"
RESULTS_PREVIOUS = RESULTS_DIR / "results_previous.json"
RESULTS_CURRENT = RESULTS_DIR / "results_current.json"

SKIP = {"__framework__"}

# Directory names that the recursive test walker must never descend into.
# These hold infrastructure / CI artifacts, not runnable tests.
DISCOVERY_SKIP_DIRS = {
    "__framework__",
    "_investigation",
    "_image-test-output",
    "_results",
    "RecompiledScripts",
    "RecompiledTags",
}


def discover_tests(tests_dir, expected_filename="output.txt"):
    """Walk `tests_dir` recursively and yield each discovered test's relative
    path name (with forward-slashes) in sorted order.

    A directory is considered a test iff it contains both `test.swf` and the
    expected-output file (`output.txt` by default). Walks skip any directory
    whose name is in `DISCOVERY_SKIP_DIRS` and stops descending once it has
    found a test (tests don't nest inside each other)."""
    results = []

    def _walk(current):
        # If this directory is itself a test, record it and don't descend.
        if (current / "test.swf").exists() and (current / expected_filename).exists():
            rel = current.relative_to(tests_dir)
            rel_str = rel.as_posix()
            if rel_str and rel_str != ".":
                results.append(rel_str)
            return
        # Otherwise recurse into children.
        try:
            children = sorted(current.iterdir())
        except (NotADirectoryError, PermissionError):
            return
        for child in children:
            if not child.is_dir():
                continue
            if child.name in DISCOVERY_SKIP_DIRS:
                continue
            if child.name in SKIP:
                continue
            _walk(child)

    _walk(tests_dir)
    return sorted(results)

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


def get_max_execution_duration(test_dir):
    """Parse max_execution_duration from test.toml [player_options].
    Returns duration in milliseconds, or 0 if not set."""
    toml_path = test_dir / "test.toml"
    if toml_path.exists():
        text = toml_path.read_text()
        # Match: max_execution_duration = { secs = N, nanos = N }
        m = re.search(
            r"max_execution_duration\s*=\s*\{\s*secs\s*=\s*(\d+)\s*,\s*nanos\s*=\s*(\d+)\s*\}",
            text,
        )
        if m:
            secs = int(m.group(1))
            nanos = int(m.group(2))
            return secs * 1000 + nanos // 1_000_000
    return 0


def get_epsilon(test_dir):
    """Parse [approximations] epsilon from test.toml, default 0 (exact match)."""
    toml_path = test_dir / "test.toml"
    if toml_path.exists():
        try:
            import tomllib
            with open(toml_path, "rb") as f:
                data = tomllib.load(f)
            approx = data.get("approximations", {})
            eps = approx.get("epsilon", 0.0)
            return float(eps)
        except Exception:
            text = toml_path.read_text()
            m = re.search(r"epsilon\s*=\s*([0-9.eE+-]+)", text)
            if m:
                return float(m.group(1))
    return 0.0


def get_number_patterns(test_dir):
    """Parse [approximations] number_patterns from test.toml. Returns a list of
    compiled regex objects, or empty list if none. Each regex's capture groups
    (excluding group 0) are compared as floats with epsilon tolerance."""
    toml_path = test_dir / "test.toml"
    if not toml_path.exists():
        return []
    try:
        import tomllib
        with open(toml_path, "rb") as f:
            data = tomllib.load(f)
        approx = data.get("approximations", {})
        patterns = approx.get("number_patterns", [])
        return [re.compile(p) for p in patterns]
    except Exception:
        return []


def _lines_approx_equal(actual_line, expected_line, epsilon, number_patterns=None):
    """Check if two lines are approximately equal (for numeric values).
    If `number_patterns` is provided, also try matching each regex against
    both lines and comparing capture-group values numerically (matches
    Ruffle's test framework behavior for [approximations.number_patterns])."""
    if actual_line == expected_line:
        return True
    if epsilon <= 0:
        return False
    # Try to parse both as a single number and compare with epsilon
    try:
        a = float(actual_line)
        e = float(expected_line)
        return abs(a - e) <= epsilon
    except (ValueError, OverflowError):
        pass
    # Try regex-based numeric comparison via [approximations.number_patterns]
    if number_patterns:
        for pattern in number_patterns:
            am = pattern.search(actual_line)
            em = pattern.search(expected_line)
            if am is None or em is None:
                continue
            if len(am.groups()) != len(em.groups()):
                continue
            try:
                groups_match = all(
                    abs(float(av) - float(ev)) <= epsilon
                    for av, ev in zip(am.groups(), em.groups())
                )
            except (ValueError, OverflowError, TypeError):
                continue
            if not groups_match:
                continue
            # Strip all matches of this pattern from both lines, then compare remainders
            stripped_a = pattern.sub("", actual_line)
            stripped_e = pattern.sub("", expected_line)
            if stripped_a == stripped_e:
                return True
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
    """Find child .swf/.png/.jpg files (non-test.swf) in a test directory."""
    children = []
    image_exts = {".png", ".jpg", ".jpeg"}
    for f in sorted(test_dir.iterdir()):
        if f.suffix == ".swf" and f.name != "test.swf":
            children.append(f)
        elif f.suffix.lower() in image_exts:
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
            proc = subprocess.Popen(
                ["bash", "-c", "ulimit -v 4194304; exec \"$@\"", "--",
                 str(RECOMP_BIN), str(RECOMP_CONFIG)],
                cwd=str(tmp),
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
            )
            proc.communicate(timeout=30)
            if proc.returncode != 0:
                return False
        except subprocess.TimeoutExpired:
            proc.kill()
            proc.wait()
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


def _detect_image_child(swf_path):
    """Check if a .swf file is actually an image (PNG/JPEG). Returns (width, height) or None."""
    try:
        with open(swf_path, "rb") as f:
            header = f.read(32)
        if len(header) < 8:
            return None
        # PNG: magic bytes 89 50 4E 47 0D 0A 1A 0A, IHDR at offset 8
        if header[:8] == b'\x89PNG\r\n\x1a\n':
            if len(header) >= 24:
                import struct
                width = struct.unpack(">I", header[16:20])[0]
                height = struct.unpack(">I", header[20:24])[0]
                return (width, height)
        # JPEG: magic FF D8 FF
        if header[:3] == b'\xff\xd8\xff':
            # Parse JPEG markers to find SOF0/SOF2 for dimensions
            with open(swf_path, "rb") as f:
                import struct
                f.read(2)  # skip SOI
                while True:
                    marker = f.read(2)
                    if len(marker) < 2:
                        break
                    if marker[0] != 0xFF:
                        break
                    m = marker[1]
                    if m in (0xC0, 0xC2):  # SOF0 or SOF2
                        seg = f.read(7)
                        if len(seg) >= 7:
                            height = struct.unpack(">H", seg[3:5])[0]
                            width = struct.unpack(">H", seg[5:7])[0]
                            return (width, height)
                    elif m == 0xD9:  # EOI
                        break
                    elif m == 0xDA:  # SOS — no SOF found
                        break
                    else:
                        seg_len_raw = f.read(2)
                        if len(seg_len_raw) < 2:
                            break
                        seg_len = struct.unpack(">H", seg_len_raw)[0]
                        f.seek(seg_len - 2, 1)
    except (OSError, struct.error):
        pass
    return None


def generate_image_movie_file(child_swf_name, build_dir, image_width, image_height, file_size, movie_id=1):
    """Generate a synthetic MovieEntry C file for an image loaded via loadMovie.

    Image MovieEntries have swf_version=0 to signal the runtime that this is an
    image load (not a real SWF). The runtime uses stage_width/stage_height as the
    image dimensions.
    """
    prefix = _sanitize_prefix(child_swf_name)
    lines = []
    lines.append(f"// Auto-generated image MovieEntry for {child_swf_name}")
    lines.append("#include <libswf/swf.h>")
    lines.append("")
    lines.append(f"static void {prefix}_tagInit(SWFAppContext* app_context) {{ (void)app_context; }}")
    lines.append(f"static void {prefix}_frame0(SWFAppContext* app_context) {{ (void)app_context; }}")
    lines.append(f"static frame_func {prefix}_frame_funcs[] = {{ {prefix}_frame0, NULL }};")
    lines.append("")
    lines.append(f"MovieEntry {prefix}_movie_entry = {{")
    lines.append(f'    .filename = "{child_swf_name}",')
    lines.append(f"    .frame_funcs = {prefix}_frame_funcs,")
    lines.append(f"    .init_func = {prefix}_tagInit,")
    lines.append(f"    .swf_version = 0,")  # 0 = image (not a real SWF)
    lines.append(f"    .frame_count = 1,")
    lines.append(f"    .stage_width = {image_width},")
    lines.append(f"    .stage_height = {image_height},")
    lines.append(f"    .file_size = {file_size},")
    lines.append(f"    .movie_id = {movie_id},")
    lines.append(f"    .transform_data_ptr = NULL,")
    lines.append(f"}};")
    out_path = build_dir / f"movie_{prefix}.c"
    out_path.write_text("\n".join(lines))
    return prefix


def generate_child_movie_file(child_swf_name, child_recomp_dir, build_dir, swf_file_size=0, movie_id=1, string_id_offset=0, is_prelude=False):
    """Generate a self-contained C file for a child SWF movie.

    Reads the recompiled C files from child_recomp_dir and generates a single
    movie_<prefix>.c file in build_dir that wraps all symbols with a unique prefix.
    Returns the prefix used, or None on failure.

    movie_id: unique ID for this child movie (1, 2, 3, ...). Used for per-movie
    export table isolation. Char IDs are offset by movie_id * 1000 to avoid
    dictionary collisions with the parent movie.
    """
    prefix = _sanitize_prefix(child_swf_name)

    # Read the child's constants.h to extract SWF_VERSION and frame dimensions
    constants_h = child_recomp_dir / "RecompiledTags" / "constants.h"
    swf_version = 8
    frame_width = 550
    frame_height = 400
    frame_count_val = 1
    if constants_h.exists():
        text = constants_h.read_text(errors="replace")
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
        text = out_h.read_text(errors="replace")
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
        text = script_decls.read_text(errors="replace")
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
        script_defs_source = script_defs_path.read_text(encoding="latin-1")
        for m in re.finditer(r'char\*\s+(str_\d+)\s*=\s*(".*?")\s*;', script_defs_source):
            str_defs.append((m.group(1), m.group(2)))
        # Also find buffer-type strings: char str_15[17];
        for m in re.finditer(r'\b(str_\d+)\b', script_defs_source):
            if m.group(1) not in str_names:
                str_names.append(m.group(1))
        for m in re.finditer(r"#define\s+MAX_STRING_ID\s+(\d+)", script_defs_source):
            max_string_id = max(max_string_id, int(m.group(1)))

    # Read the child's script_N.c files (exclude script_defs.c — handled above)
    script_sources = {}
    scripts_dir = child_recomp_dir / "RecompiledScripts"
    if scripts_dir.exists():
        for f in sorted(scripts_dir.iterdir()):
            if (f.name.startswith("script_") and f.suffix == ".c"
                    and f.name != "script_defs.c"):
                script_sources[f.name] = f.read_text(encoding="latin-1")

    # Read the child's tagMain.c
    tag_main = child_recomp_dir / "RecompiledTags" / "tagMain.c"
    tag_main_text = ""
    if tag_main.exists():
        tag_main_text = tag_main.read_text(encoding="latin-1")

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

    # draws.c arrays referenced from tagMain (passed by raw pointer to draw/define
    # tags). Each child must own its prefixed copy so they don't collide.
    DRAWS_ARRAY_NAMES = (
        "shape_data", "transform_data", "color_data", "uninv_mat_data",
        "gradient_data", "bitmap_data", "glyph_data", "text_data",
        "text_char_codes", "cxform_data", "morph_end_shape_data",
        "morph_end_color_data", "sound_data", "path_data",
    )
    if tag_main_text:
        for arr_name in DRAWS_ARRAY_NAMES:
            if re.search(rf'\b{arr_name}\b', tag_main_text):
                all_renames[arr_name] = f'{prefix}_{arr_name}'

    # Build a single compiled regex for all renames (single-pass replacement)
    # Match known symbol prefixes and check against rename dict in callback
    if all_renames:
        _rename_pattern = re.compile(
            r'\b(str_\d+|script_\d+|func2?_\w+|button_\d+_\w+'
            r'|clip_action(?:s)?_\d+|sprite_\d+_frame_\w+'
            r'|shape_data|transform_data|color_data|uninv_mat_data'
            r'|gradient_data|bitmap_data|glyph_data|text_data'
            r'|text_char_codes|cxform_data|morph_end_shape_data'
            r'|morph_end_color_data|sound_data|path_data)\b')
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

    # Offset string_ids in PUSH_STR_ID calls to avoid var_array collisions
    # between parent and child movies. The third argument is the string_id.
    _sid_offset = string_id_offset
    if _sid_offset > 0:
        _push_str_id_pattern = re.compile(
            r'PUSH_STR_ID\(([^,]+),\s*([^,]+),\s*(\d+)\)')
        def apply_string_id_offset(text):
            def _offset_sid(m):
                name, length, sid = m.group(1), m.group(2), int(m.group(3))
                return f'PUSH_STR_ID({name}, {length}, {sid + _sid_offset})'
            return _push_str_id_pattern.sub(_offset_sid, text)
    else:
        def apply_string_id_offset(text):
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
    # Phase A side table type (SpriteFrameScriptEntry) is referenced by
    # the child's tagMain.c emission (renamed per-prefix). The include
    # is stripped from child sources; the wrapper has to provide it.
    lines.append("#include <sprite_frame_scripts.h>")
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
    # Forward declarations for any draws.c arrays referenced from tagMain.
    # The actual definitions are appended later (extracted from child draws.c).
    _draws_extern_types = {
        "shape_data": "u32", "transform_data": "float", "color_data": "float",
        "uninv_mat_data": "float", "gradient_data": "u8", "bitmap_data": "u8",
        "glyph_data": "u32", "text_data": "u32", "text_char_codes": "u16",
        "cxform_data": "float", "morph_end_shape_data": "float",
        "morph_end_color_data": "float", "sound_data": "u8", "path_data": "float",
    }
    for arr_name in DRAWS_ARRAY_NAMES:
        if arr_name in all_renames:
            ctype = _draws_extern_types[arr_name]
            lines.append(f"extern {ctype} {prefix}_{arr_name}[];")
    lines.append("")

    # Include script_defs.c content (string definitions + function implementations)
    if script_defs_source:
        modified = script_defs_source
        # Remove #include lines and #define MAX_STRING_ID
        modified = re.sub(r'#include\s+[<"].*?[>"]\s*\n', '', modified)
        modified = re.sub(r'#define\s+MAX_STRING_ID\s+\d+\s*\n?', '', modified)
        # Apply all symbol renames and string_id offsets
        modified = apply_renames(modified)
        modified = apply_string_id_offset(modified)
        lines.append(modified)
    lines.append("")

    # Script function implementations
    for fname, source in script_sources.items():
        modified = source
        # Remove #include lines
        modified = re.sub(r'#include\s+[<"].*?[>"]\s*\n', '', modified)
        # Apply all symbol renames and string_id offsets
        modified = apply_renames(modified)
        modified = apply_string_id_offset(modified)
        lines.append(modified)
        lines.append("")

    # Apply char_id offsetting to avoid dictionary collisions with parent movie.
    # Each child gets a fixed offset of movie_id * 1000 added to all char_ids.
    char_id_offset = movie_id * 1000
    if tag_main_text and char_id_offset > 0:
        def _offset_char_id(m):
            """Add char_id_offset to the integer char_id argument in tag calls."""
            prefix_part = m.group(1)
            char_id_val = int(m.group(2))
            suffix_part = m.group(3)
            return f"{prefix_part}{char_id_val + char_id_offset}{suffix_part}"

        # tagDefineSprite(app_context, CHAR_ID, ...) — 2nd arg
        tag_main_text = re.sub(
            r'(tagDefineSprite\(app_context,\s*)(\d+)(\s*,)',
            _offset_char_id, tag_main_text)
        # tagDefineShape(app_context, CHAR_TYPE_*, CHAR_ID, ...) — 3rd arg
        tag_main_text = re.sub(
            r'(tagDefineShape\(app_context,\s*\w+,\s*)(\d+)(\s*,)',
            _offset_char_id, tag_main_text)
        # tagDefineMorphShape(app_context, CHAR_ID, ...) — 2nd arg
        tag_main_text = re.sub(
            r'(tagDefineMorphShape\(app_context,\s*)(\d+)(\s*,)',
            _offset_char_id, tag_main_text)
        # tagDefineEditText(app_context, CHAR_ID, ...) — 2nd arg
        tag_main_text = re.sub(
            r'(tagDefineEditText\(app_context,\s*)(\d+)(\s*,)',
            _offset_char_id, tag_main_text)
        # tagDefineButton(app_context, CHAR_ID, ...) — 2nd arg
        tag_main_text = re.sub(
            r'(tagDefineButton\(app_context,\s*)(\d+)(\s*,)',
            _offset_char_id, tag_main_text)
        # tagRegisterExport(app_context, "name", CHAR_ID) — 3rd arg (last, before ')')
        tag_main_text = re.sub(
            r'(tagRegisterExport\(app_context,\s*"[^"]*",\s*)(\d+)(\s*\))',
            _offset_char_id, tag_main_text)
        # tagPlaceObject2 and variants — CHAR_ID is 3rd arg (after app_context, depth)
        # Match: tagPlaceObject2*(app_context, DEPTH, CHAR_ID, ...)
        tag_main_text = re.sub(
            r'(tagPlaceObject2\w*\(app_context,\s*\d+,\s*)(\d+)(\s*,)',
            _offset_char_id, tag_main_text)
        # tagDefineFont(app_context, CHAR_ID, ...) — 2nd arg
        tag_main_text = re.sub(
            r'(tagDefineFont\(app_context,\s*)(\d+)(\s*,)',
            _offset_char_id, tag_main_text)
        # tagDefineSoundMeta(app_context, CHAR_ID, ...) — 2nd arg
        tag_main_text = re.sub(
            r'(tagDefineSoundMeta\(app_context,\s*)(\d+)(\s*,)',
            _offset_char_id, tag_main_text)
        # tagDefineVideoMeta(app_context, CHAR_ID, ...) — 2nd arg
        tag_main_text = re.sub(
            r'(tagDefineVideoMeta\(app_context,\s*)(\d+)(\s*,)',
            _offset_char_id, tag_main_text)
        # button_N_hit_char_id references (in tagDefineButton calls)
        # These are embedded as a bare integer argument for hit char_id.
        # Also offset char_id references in sprite_frame_funcs arrays via
        # tagPlaceObject2 calls inside sprite frame functions (already handled above).

    # Frame functions from tagMain.c
    if tag_main_text:
        modified = tag_main_text
        # Remove includes
        modified = re.sub(r'#include\s+[<"].*?[>"]\s*\n', '', modified)
        # Remove FrameLabelEntry typedef (already defined in runtime)
        modified = re.sub(
            r'// Frame labels.*?size_t frame_label_count = \d+;',
            '', modified, flags=re.DOTALL)
        # Strip `quit_swf = 1;` — the recompiler emits this in the last frame of
        # single-/few-frame movies to terminate the test, but for a child SWF
        # it would also stop the parent's frame loop.
        modified = re.sub(r'\n\s*quit_swf\s*=\s*1\s*;\s*\n', '\n', modified)
        # Prefix frame_N functions
        frame_funcs_in_tag = list(set(re.findall(r'\b(frame_\d+)\b', tag_main_text)))
        for ff in frame_funcs_in_tag:
            modified = re.sub(rf'\b{ff}\b', f'{prefix}_{ff}', modified)
        # Apply all symbol renames and string_id offsets (str_N, script_N, func_*)
        modified = apply_renames(modified)
        modified = apply_string_id_offset(modified)
        # Rename frame_funcs array
        modified = modified.replace('frame_func frame_funcs[]', f'frame_func {prefix}_frame_funcs[]')
        # Rename frame_label_data and frame_label_count
        modified = re.sub(r'\bframe_label_data\b', f'{prefix}_frame_label_data', modified)
        modified = re.sub(r'\bframe_label_count\b', f'{prefix}_frame_label_count', modified)
        # Rename Phase A side table (sprite_frame_scripts) per-prefix so
        # parent and child don't collide on the global symbol. The runtime
        # accessor only consults the most-recently-registered table; the
        # child's tagInit call to tagInitSpriteFrameScripts is stripped
        # below so the parent's registration survives. Session A's table
        # is dead code anyway — future phases that consume it for child
        # sprites will need a different registration model (per-MovieEntry
        # accessor, or a list of tables).
        modified = re.sub(r'\bsprite_frame_scripts_data\b', f'{prefix}_sprite_frame_scripts_data', modified)
        modified = re.sub(r'\bsprite_frame_scripts_data_count\b', f'{prefix}_sprite_frame_scripts_data_count', modified)
        # Strip the child's tagInitSpriteFrameScripts call so it doesn't
        # overwrite the parent's registration. Match the recompiler
        # emission shape: a single line with a leading tab.
        modified = re.sub(r'\n\s*tagInitSpriteFrameScripts\([^)]*\)\s*;\s*\n', '\n', modified)
        # Rename tagInit
        modified = modified.replace('void tagInit(', f'void {prefix}_tagInit(')
        # Rename initVarArray call's MAX_STRING_ID (with string_id offset)
        modified = re.sub(r'initVarArray\(MAX_STRING_ID\)',
                          f'initVarArray({max_string_id + string_id_offset})', modified)
        lines.append(modified)
        lines.append("")

    # Extract and include child's draws.c array definitions. Anything tagMain.c
    # passes to a draw/define tag as a raw pointer (sound_data + N, etc.) needs
    # to live in the combined wrapper, with prefixed names so multiple children
    # don't collide.
    draws_c_path = child_recomp_dir / "RecompiledTags" / "draws.c"
    has_child_transforms = False
    extracted_array_names = set()
    if draws_c_path.exists():
        draws_text = draws_c_path.read_text(encoding="latin-1")
        # All raw-data arrays emitted in draws.c (see SWFRecomp/src/swf.cpp).
        # Each is matched by its full type signature so the regex doesn't drift.
        draws_arrays = [
            (r'u32\s+shape_data\s*\[\s*3?\s*\*?\s*\d+\s*\]\s*\[\s*4\s*\]', 'shape_data'),
            (r'float\s+transform_data\s*\[\s*\d+\s*\]\s*\[\s*16\s*\]', 'transform_data'),
            (r'float\s+color_data\s*\[\s*\d+\s*\]\s*\[\s*4\s*\]', 'color_data'),
            (r'float\s+uninv_mat_data\s*\[\s*\d+(?:\s*\*\s*16)?\s*\]', 'uninv_mat_data'),
            (r'u8\s+gradient_data\s*\[\s*\d+\s*\]\s*\[\s*4\s*\]', 'gradient_data'),
            (r'u8\s+bitmap_data\s*\[\s*\d+\s*\]', 'bitmap_data'),
            (r'u32\s+glyph_data\s*\[\s*\d+\s*\]\s*\[\s*1\s*\]', 'glyph_data'),
            (r'u32\s+text_data\s*\[\s*\d+\s*\]', 'text_data'),
            (r'u16\s+text_char_codes\s*\[\s*\d+\s*\]', 'text_char_codes'),
            (r'float\s+cxform_data\s*\[\s*\d+(?:\s*\*\s*20)?\s*\]', 'cxform_data'),
            (r'float\s+morph_end_shape_data\s*\[\s*\d+\s*\]\s*\[\s*2\s*\]', 'morph_end_shape_data'),
            (r'float\s+morph_end_color_data\s*\[\s*\d+\s*\]\s*\[\s*4\s*\]', 'morph_end_color_data'),
            (r'u8\s+sound_data\s*\[\s*\d+\s*\]', 'sound_data'),
            (r'float\s+path_data\s*\[\s*\d+\s*\]\s*\[\s*3\s*\]', 'path_data'),
        ]
        for sig_re, name in draws_arrays:
            m = re.search(rf'({sig_re}\s*=\s*\{{.*?\}};)', draws_text, re.DOTALL)
            if m:
                arr_def = m.group(1)
                # Rename only the first occurrence of `name` (the declaration);
                # don't touch any inline references inside the initializer.
                arr_def = re.sub(rf'\b{name}\b', f'{prefix}_{name}', arr_def, count=1)
                lines.append(arr_def)
                lines.append("")
                extracted_array_names.add(name)
                if name == 'transform_data':
                    has_child_transforms = True

    # Generate the movie entry struct access function
    lines.append(f"// Movie entry for {child_swf_name}")
    lines.append(f"#include <libswf/swf.h>")
    lines.append("")
    td_ptr = f"{prefix}_transform_data" if has_child_transforms else "NULL"
    lines.append(f"MovieEntry {prefix}_movie_entry = {{")
    lines.append(f'    .filename = "{child_swf_name}",')
    lines.append(f"    .frame_funcs = {prefix}_frame_funcs,")
    lines.append(f"    .init_func = {prefix}_tagInit,")
    lines.append(f"    .swf_version = {swf_version},")
    lines.append(f"    .frame_count = {frame_count_val},")
    lines.append(f"    .stage_width = {frame_width},")
    lines.append(f"    .stage_height = {frame_height},")
    lines.append(f"    .file_size = {swf_file_size},")
    lines.append(f"    .movie_id = {movie_id},")
    lines.append(f"    .is_prelude = {1 if is_prelude else 0},")
    lines.append(f"    .transform_data_ptr = {td_ptr},")
    lines.append(f"}};")
    lines.append("")

    # Write the file
    out_path = build_dir / f"movie_{prefix}.c"
    out_path.write_text("\n".join(lines), encoding="latin-1")
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
    lines.append("MovieEntry* getPreludeEntry(int idx) {")
    lines.append("    int count = 0;")
    lines.append("    for (int i = 0; g_movie_entries[i] != NULL; i++) {")
    lines.append("        if (g_movie_entries[i]->is_prelude) {")
    lines.append("            if (count == idx) return g_movie_entries[i];")
    lines.append("            count++;")
    lines.append("        }")
    lines.append("    }")
    lines.append("    return NULL;")
    lines.append("}")
    lines.append("")

    out_path = build_dir / "movie_registry.c"
    out_path.write_text("\n".join(lines))


def find_data_files(test_dir):
    """Find data files (non-.swf, non-.fla, non-config) in a test directory.
    These are files like testvars.txt that loadVariables loads at runtime."""
    skip_names = {"test.swf", "test.fla", "test.toml", "test.as", "output.txt",
                   "output.ruffle.txt", "input.json", "test_harness.c"}
    skip_suffixes = {".swf", ".fla", ".toml", ".json", ".c", ".h", ".py"}
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
        if content:
            hex_bytes = ", ".join(f"0x{b:02x}" for b in content)
            lines.append(f"static const char {var_name}[] = {{ {hex_bytes}, 0x00 }};")
        else:
            lines.append(f"static const char {var_name}[] = {{ 0x00 }};")
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
    """Run SWFRecomp on test.swf if not already done (or if forced).

    Returns (success, stderr).
    """
    if not force and (test_dir / "RecompiledScripts").exists():
        return True, ""

    # Remove old output if forcing
    if force:
        for d in ["RecompiledScripts", "RecompiledTags"]:
            p = test_dir / d
            if p.exists():
                shutil.rmtree(p)

    try:
        proc = subprocess.Popen(
            ["bash", "-c", "ulimit -v 4194304; exec \"$@\"", "--",
             str(RECOMP_BIN), str(RECOMP_CONFIG)],
            cwd=str(test_dir),
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        _, stderr = proc.communicate(timeout=30)
        return proc.returncode == 0, stderr.decode("utf-8", errors="replace")
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait()
        return False, "recompiler timed out"


def get_mock_date_time(test_dir):
    """Parse mock_date_time from test.toml if present."""
    toml_path = test_dir / "test.toml"
    if toml_path.exists():
        text = toml_path.read_text()
        m = re.search(r"mock_date_time\s*=\s*(\d+)", text)
        if m:
            return int(m.group(1))
    return None


def get_self_load(test_dir):
    """Detect if the test loads itself (test.swf loads test.swf into a child MC).

    Auto-detects by scanning recompiled scripts for a "test.swf" string literal.
    Falls back to explicit self_load = true in test.toml for backward compatibility.
    """
    # Auto-detect: scan recompiled scripts for "test.swf" string reference
    recomp_dir = test_dir / "RecompiledScripts"
    if recomp_dir.exists():
        for f in recomp_dir.iterdir():
            if f.suffix == '.c' and '"test.swf"' in f.read_text(errors="replace"):
                return True
    # Fallback: explicit flag in test.toml
    toml_path = test_dir / "test.toml"
    if toml_path.exists():
        text = toml_path.read_text()
        if re.search(r"self_load\s*=\s*true", text):
            return True
    return False


def compile_native(test_dir, num_frames, build_dir, mode="no-graphics", has_image_comparisons=False, asan=False, use_ccache=True):
    """Compile generated C code with runtime into native binary.

    mode is one of: "no-graphics", "graphics", "graphics-headless-legacy".
    """
    mem_dir = build_dir / "memory"
    mem_dir.mkdir(exist_ok=True)

    # Copy runtime sources
    core_sources = [
        "src/actionmodern/action.c",
        "src/actionmodern/math.c",
        "src/actionmodern/date.c",
        "src/actionmodern/registered_class.c",
        "src/actionmodern/timer.c",
        "src/actionmodern/variables.c",
        "src/actionmodern/object.c",
        "src/actionmodern/action_queue.c",
        "src/actionmodern/sprite_frame_scripts.c",
        "src/actionmodern/unicode_case_tables.h",
        "src/utils.c",
        "src/libswf/tag.c",
        "src/libswf/tag_stubs.c",
        "src/libswf/shape_hit_test.c",
        "src/libswf/ng_shared.c",
        "src/libswf/hit_test.c",
        "src/memory/heap.c",
    ]
    if mode == "graphics-headless-legacy":
        core_sources.append("src/libswf/swf_headless.c")
        core_sources.append("src/libswf/capture.c")
        core_sources.append("src/rendering/render_webgpu.c")
    elif mode == "graphics":
        # Full graphics-mode runtime + offscreen Dawn rendering, native target.
        core_sources.append("src/libswf/swf.c")
        core_sources.append("src/libswf/capture.c")
        core_sources.append("src/libswf/graphics_stubs.c")
        core_sources.append("src/libswf/input_events.c")
        core_sources.append("src/audio/audio.c")
        core_sources.append("src/audio/audio_output_web.c")  # native stub branch
        core_sources.append("src/rendering/render_webgpu.c")
    else:
        core_sources.append("src/libswf/swf_core.c")
    for src in core_sources:
        shutil.copy2(SWFMODERN / src, build_dir)

    shutil.copy2(SWFMODERN / "lib/c-hashmap/map.c", build_dir)
    shutil.copy2(SWFMODERN / "lib/o1heap/o1heap.c", build_dir)
    shutil.copy2(SWFMODERN / "lib/o1heap/o1heap.h", build_dir)
    shutil.copy2(SWFMODERN / "include/memory/heap.h", mem_dir)
    # Copy libtess2 tessellation library
    libtess2_dir = SWFMODERN / "third_party" / "libtess2"
    if libtess2_dir.exists():
        for f in libtess2_dir.iterdir():
            if f.suffix in (".c", ".h"):
                shutil.copy2(f, build_dir)
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

    # Read parent's MAX_STRING_ID to offset child string_ids (avoid var_array collision)
    parent_max_string_id = 0
    parent_script_defs = build_dir / "script_defs.c"
    if parent_script_defs.exists():
        for m in re.finditer(r'#define\s+MAX_STRING_ID\s+(\d+)', parent_script_defs.read_text(errors="replace")):
            parent_max_string_id = max(parent_max_string_id, int(m.group(1)))

    next_string_id_offset = parent_max_string_id + 1  # +1 to leave a gap

    for child_idx, child_swf in enumerate(child_swfs):
        child_movie_id = child_idx + 1  # 0 = main SWF, 1+ = children
        child_file_size = child_swf.stat().st_size if child_swf.exists() else 0

        # Check if child is an image (PNG/JPEG with .swf extension)
        image_dims = _detect_image_child(child_swf)
        if image_dims is not None:
            prefix = generate_image_movie_file(
                child_swf.name, build_dir,
                image_width=image_dims[0], image_height=image_dims[1],
                file_size=child_file_size, movie_id=child_movie_id)
            if prefix:
                child_prefixes.append(prefix)
            continue

        child_recomp_dir = build_dir / f"_child_{_sanitize_prefix(child_swf.name)}"
        child_recomp_dir.mkdir(exist_ok=True)
        if recompile_child_swf(child_swf, child_recomp_dir):
            # Detect prelude SWFs by filename convention (prelude_*.swf)
            child_is_prelude = child_swf.name.startswith("prelude_")
            prefix = generate_child_movie_file(
                child_swf.name, child_recomp_dir, build_dir,
                swf_file_size=child_file_size, movie_id=child_movie_id,
                string_id_offset=next_string_id_offset,
                is_prelude=child_is_prelude)
            if prefix:
                child_prefixes.append(prefix)
                # Read child's MAX_STRING_ID and advance offset for next child
                child_defs = child_recomp_dir / "RecompiledScripts" / "script_defs.c"
                if child_defs.exists():
                    child_max = 0
                    for m in re.finditer(r'#define\s+MAX_STRING_ID\s+(\d+)', child_defs.read_text(errors="replace")):
                        child_max = max(child_max, int(m.group(1)))
                    next_string_id_offset += child_max + 1

    # Handle self-loading SWFs (test.swf loads itself into a child MC)
    self_load = get_self_load(test_dir)
    if self_load:
        has_children = True
        # Parse SWF version and dimensions from constants.h
        constants_h = build_dir / "constants.h"
        sl_version = 8
        sl_width = 550
        sl_height = 400
        sl_frame_count = 1
        if constants_h.exists():
            ctext = constants_h.read_text(errors="replace")
            m = re.search(r"#define\s+SWF_VERSION\s+(\d+)", ctext)
            if m: sl_version = int(m.group(1))
            m = re.search(r"#define\s+FRAME_WIDTH\s+(\d+)", ctext)
            if m: sl_width = int(m.group(1))
            m = re.search(r"#define\s+FRAME_HEIGHT\s+(\d+)", ctext)
            if m: sl_height = int(m.group(1))
            m = re.search(r"#define\s+SWF_FRAME_COUNT\s+(\d+)", ctext)
            if m: sl_frame_count = int(m.group(1))
        # Get file size
        test_swf_path = test_dir / "test.swf"
        sl_file_size = test_swf_path.stat().st_size if test_swf_path.exists() else 0
        # Generate a MovieEntry for test.swf that references the main movie's functions
        lines = []
        lines.append("// Auto-generated self-load MovieEntry for test.swf")
        lines.append("#include <libswf/swf.h>")
        lines.append("")
        lines.append("extern void tagInit(SWFAppContext* app_context);")
        lines.append("extern frame_func frame_funcs[];")
        lines.append("")
        lines.append("MovieEntry self_movie_entry = {")
        lines.append('    .filename = "test.swf",')
        lines.append("    .frame_funcs = frame_funcs,")
        lines.append("    .init_func = tagInit,")
        lines.append(f"    .swf_version = {sl_version},")
        lines.append(f"    .frame_count = {sl_frame_count},")
        lines.append(f"    .stage_width = {sl_width},")
        lines.append(f"    .stage_height = {sl_height},")
        lines.append(f"    .file_size = {sl_file_size},")
        lines.append("    .movie_id = 0,")  # Self-load: same movie as parent
        lines.append("};")
        (build_dir / "movie_self.c").write_text("\n".join(lines))
        child_prefixes.append("self")

    if has_children:
        generate_movie_registry(child_prefixes, build_dir)

    # Handle data files (loadVariables tests: testvars.txt, etc.)
    data_files = find_data_files(test_dir)
    has_data_files = len(data_files) > 0
    if has_data_files:
        generate_data_registry(data_files, build_dir)

    # Handle test harness (per-test custom C code, e.g. ExternalInterface mock)
    test_harness = test_dir / "test_harness.c"
    has_test_harness = test_harness.exists()
    if has_test_harness:
        shutil.copy2(test_harness, build_dir)

    # Compile
    inc = SWFMODERN / "include"
    extra_defines = []
    mock_time = get_mock_date_time(test_dir)
    if mock_time is None:
        # Default mock time matches Ruffle's deterministic mode:
        # 2001-02-03 04:05:06 NPT (UTC+5:45) = 981152406000 ms since epoch
        mock_time = 981152406000
    extra_defines.append(f"-DMOCK_DATE_TIME={mock_time}LL")
    viewport = get_viewport_dimensions(test_dir)
    if viewport is not None:
        extra_defines.append(f"-DVIEWPORT_WIDTH={viewport[0]}")
        extra_defines.append(f"-DVIEWPORT_HEIGHT={viewport[1]}")
    if has_children:
        extra_defines.append("-DHAS_CHILD_MOVIES")
    if has_data_files:
        extra_defines.append("-DHAS_DATA_FILES")
    if has_test_harness:
        extra_defines.append("-DHAS_TEST_HARNESS")
    # Pass max execution duration for script timeout
    max_exec_ms = get_max_execution_duration(test_dir)
    if max_exec_ms > 0:
        extra_defines.append(f"-DMAX_EXECUTION_MS={max_exec_ms}")
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
    # Build compiler flags based on mode
    mode_defines = []
    mode_includes = []
    mode_libs = []
    if mode in ("graphics-headless-legacy", "graphics"):
        if mode == "graphics-headless-legacy":
            mode_defines = ["-DNO_GRAPHICS", "-DHEADLESS_GRAPHICS", "-DUSE_WEBGPU", "-DNDEBUG"]
        else:  # mode == "graphics"
            # Full graphics native: NO_GRAPHICS / HEADLESS_GRAPHICS NOT defined;
            # OFFSCREEN_RENDER tells render_webgpu.c to skip SDL3 / browser paths.
            mode_defines = ["-DUSE_WEBGPU", "-DOFFSCREEN_RENDER", "-DNDEBUG"]
        if has_image_comparisons:
            mode_defines.append("-DHEADLESS_RENDER_ENABLED")
        mode_includes = [
            f"-I{inc}/rendering",
            f"-I{STB_DIR}",
            f"-I{DAWN_INSTALL}/include",
        ]
        mode_libs = [
            str(DAWN_INSTALL / "lib" / "libwebgpu_dawn.a"),
            "-lstdc++", "-lpthread", "-ldl",
        ]
    else:
        mode_defines = ["-DNO_GRAPHICS"]

    # Sanitizer flags for crash debugging
    sanitizer_flags = []
    opt_level = "-O2"
    if asan:
        sanitizer_flags = ["-fsanitize=address", "-fno-omit-frame-pointer", "-g"]
        opt_level = "-O1"  # ASan needs at least -O1 but -O2 can hide issues

    # ccache speeds up repeat compiles massively (action.c alone is ~50s at -O2,
    # ~0.01s on a cache hit). Auto-detect and wrap gcc unless disabled. ccache
    # hashes preprocessed output, so hits happen whenever the preprocessed
    # source is identical — i.e. same macros that the file actually references.
    cc = ["gcc"]
    cc_env = None
    # Each test builds in a fresh tempfile.TemporaryDirectory so absolute paths
    # differ every run. -ffile-prefix-map strips the tempdir prefix from source
    # references in the preprocessed output so ccache sees identical content.
    prefix_map_flags = [f"-ffile-prefix-map={build_dir}=."]
    if use_ccache and shutil.which("ccache") and not asan:
        cc = ["ccache", "gcc"]
        cc_env = os.environ.copy()
        cc_env.setdefault("CCACHE_NOHASHDIR", "1")
        cc_env.setdefault("CCACHE_BASEDIR", "/tmp")
        cc_env.setdefault(
            "CCACHE_SLOPPINESS",
            "include_file_mtime,include_file_ctime,time_macros,locale",
        )

    # Split into two passes: per-file .o compile (cacheable), then link.
    # One-shot gcc src1.c src2.c ... -o bin bypasses ccache because ccache only
    # caches single-file compilations. Compiling per-file also lets unchanged
    # sources hit the cache while the changed generated scripts recompile.
    sources = sorted(build_dir.glob("*.c"))
    # Use "-I." for the per-test build dir and run gcc with cwd=build_dir so the
    # command line is identical across runs (no random tmpdir name embedded in
    # -I or source path). Combined with -ffile-prefix-map, this lets ccache
    # see identical preprocessed output across independent test builds.
    common_flags = [
        *mode_defines,
        f"-DMAX_FRAMES={num_frames}",
        "-D_POSIX_C_SOURCE=200809L",
        *extra_defines,
        "-I.",
        f"-I{inc}",
        f"-I{inc}/actionmodern",
        f"-I{inc}/libswf",
        f"-I{inc}/memory",
        f"-I{SWFMODERN}/lib/c-hashmap",
        *mode_includes,
        *prefix_map_flags,
        "-w",
        "-std=c17",
        opt_level,
        *sanitizer_flags,
    ]

    objects = []
    try:
        for src in sources:
            obj = src.with_suffix(".o")
            objects.append(obj)
            proc = subprocess.Popen(
                [*cc, "-c", src.name, *common_flags, "-o", obj.name],
                cwd=str(build_dir),
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE,
                env=cc_env,
            )
            stdout, stderr = proc.communicate(timeout=300)
            if proc.returncode != 0:
                return False, stderr.decode("utf-8", errors="replace")

        # Link (no ccache; linking is not the bottleneck)
        proc = subprocess.Popen(
            [
                "gcc",
                *[str(o) for o in objects],
                *sanitizer_flags,
                "-o", str(build_dir / "test_run"),
                "-lm", "-lz",
                *mode_libs,
            ],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        stdout, stderr = proc.communicate(timeout=300)
        return proc.returncode == 0, stderr.decode("utf-8", errors="replace")
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait()
        return False, "compilation timed out"


EMSDK_ENV = PROJECT_ROOT / "emsdk" / "emsdk_env.sh"


def compile_wasm(test_dir, num_frames, build_dir):
    """Compile generated C code with Emscripten into WASM.

    Reuses compile_native's setup (runtime copy, child SWFs, etc.) then
    compiles with emcc instead of gcc.  Output: build_dir/test.js + test.wasm.
    """
    mem_dir = build_dir / "memory"
    mem_dir.mkdir(exist_ok=True)

    # Copy runtime sources (NO_GRAPHICS mode)
    core_sources = [
        "src/actionmodern/action.c",
        "src/actionmodern/math.c",
        "src/actionmodern/date.c",
        "src/actionmodern/registered_class.c",
        "src/actionmodern/timer.c",
        "src/actionmodern/variables.c",
        "src/actionmodern/object.c",
        "src/actionmodern/action_queue.c",
        "src/actionmodern/sprite_frame_scripts.c",
        "src/actionmodern/unicode_case_tables.h",
        "src/utils.c",
        "src/libswf/tag.c",
        "src/libswf/ng_shared.c",
        "src/libswf/hit_test.c",
        "src/memory/heap.c",
        "src/libswf/swf_core.c",
        "src/libswf/tag_stubs.c",
        "src/libswf/shape_hit_test.c",
    ]
    for src in core_sources:
        shutil.copy2(SWFMODERN / src, build_dir)
    shutil.copy2(SWFMODERN / "lib/c-hashmap/map.c", build_dir)
    shutil.copy2(SWFMODERN / "lib/o1heap/o1heap.c", build_dir)
    shutil.copy2(SWFMODERN / "lib/o1heap/o1heap.h", build_dir)
    shutil.copy2(SWFMODERN / "include/memory/heap.h", mem_dir)
    libtess2_dir = SWFMODERN / "third_party" / "libtess2"
    if libtess2_dir.exists():
        for f in libtess2_dir.iterdir():
            if f.suffix in (".c", ".h"):
                shutil.copy2(f, build_dir)
    shutil.copy2(MAIN_C, build_dir)

    # Copy generated files for main SWF
    for folder in ["RecompiledScripts", "RecompiledTags"]:
        src_dir = test_dir / folder
        if src_dir.exists():
            for f in src_dir.iterdir():
                if f.suffix in (".c", ".h"):
                    shutil.copy2(f, build_dir)

    # Handle child SWFs (same logic as compile_native)
    child_swfs = find_child_swfs(test_dir)
    child_prefixes = []
    has_children = len(child_swfs) > 0
    parent_max_string_id = 0
    parent_script_defs = build_dir / "script_defs.c"
    if parent_script_defs.exists():
        for m in re.finditer(r'#define\s+MAX_STRING_ID\s+(\d+)', parent_script_defs.read_text(errors="replace")):
            parent_max_string_id = max(parent_max_string_id, int(m.group(1)))
    next_string_id_offset = parent_max_string_id + 1
    for child_idx, child_swf in enumerate(child_swfs):
        child_movie_id = child_idx + 1
        child_file_size = child_swf.stat().st_size if child_swf.exists() else 0
        image_dims = _detect_image_child(child_swf)
        if image_dims is not None:
            prefix = generate_image_movie_file(
                child_swf.name, build_dir,
                image_width=image_dims[0], image_height=image_dims[1],
                file_size=child_file_size, movie_id=child_movie_id)
            if prefix:
                child_prefixes.append(prefix)
            continue
        child_recomp_dir = build_dir / f"_child_{_sanitize_prefix(child_swf.name)}"
        child_recomp_dir.mkdir(exist_ok=True)
        if recompile_child_swf(child_swf, child_recomp_dir):
            child_is_prelude = child_swf.name.startswith("prelude_")
            prefix = generate_child_movie_file(
                child_swf.name, child_recomp_dir, build_dir,
                swf_file_size=child_file_size, movie_id=child_movie_id,
                string_id_offset=next_string_id_offset,
                is_prelude=child_is_prelude)
            if prefix:
                child_prefixes.append(prefix)
                child_defs = child_recomp_dir / "RecompiledScripts" / "script_defs.c"
                if child_defs.exists():
                    child_max = 0
                    for m in re.finditer(r'#define\s+MAX_STRING_ID\s+(\d+)', child_defs.read_text(errors="replace")):
                        child_max = max(child_max, int(m.group(1)))
                    next_string_id_offset += child_max + 1
    self_load = get_self_load(test_dir)
    if self_load:
        has_children = True
        constants_h = build_dir / "constants.h"
        sl_version, sl_width, sl_height, sl_frame_count = 8, 550, 400, 1
        if constants_h.exists():
            ctext = constants_h.read_text(errors="replace")
            m = re.search(r"#define\s+SWF_VERSION\s+(\d+)", ctext)
            if m: sl_version = int(m.group(1))
            m = re.search(r"#define\s+FRAME_WIDTH\s+(\d+)", ctext)
            if m: sl_width = int(m.group(1))
            m = re.search(r"#define\s+FRAME_HEIGHT\s+(\d+)", ctext)
            if m: sl_height = int(m.group(1))
            m = re.search(r"#define\s+SWF_FRAME_COUNT\s+(\d+)", ctext)
            if m: sl_frame_count = int(m.group(1))
        test_swf_path = test_dir / "test.swf"
        sl_file_size = test_swf_path.stat().st_size if test_swf_path.exists() else 0
        lines = []
        lines.append("// Auto-generated self-load MovieEntry for test.swf")
        lines.append("#include <libswf/swf.h>")
        lines.append("")
        lines.append("extern void tagInit(SWFAppContext* app_context);")
        lines.append("extern frame_func frame_funcs[];")
        lines.append("")
        lines.append("MovieEntry self_movie_entry = {")
        lines.append('    .filename = "test.swf",')
        lines.append("    .frame_funcs = frame_funcs,")
        lines.append("    .init_func = tagInit,")
        lines.append(f"    .swf_version = {sl_version},")
        lines.append(f"    .frame_count = {sl_frame_count},")
        lines.append(f"    .stage_width = {sl_width},")
        lines.append(f"    .stage_height = {sl_height},")
        lines.append(f"    .file_size = {sl_file_size},")
        lines.append("    .movie_id = 0,")
        lines.append("};")
        (build_dir / "movie_self.c").write_text("\n".join(lines))
        child_prefixes.append("self")
    if has_children:
        generate_movie_registry(child_prefixes, build_dir)
    data_files = find_data_files(test_dir)
    has_data_files = len(data_files) > 0
    if has_data_files:
        generate_data_registry(data_files, build_dir)
    test_harness = test_dir / "test_harness.c"
    has_test_harness = test_harness.exists()
    if has_test_harness:
        shutil.copy2(test_harness, build_dir)

    # Build defines
    inc = SWFMODERN / "include"
    extra_defines = ["-DNO_GRAPHICS", f"-DMAX_FRAMES={num_frames}"]
    mock_time = get_mock_date_time(test_dir)
    if mock_time is None:
        mock_time = 981152406000
    extra_defines.append(f"-DMOCK_DATE_TIME={mock_time}LL")
    if has_children:
        extra_defines.append("-DHAS_CHILD_MOVIES")
    if has_data_files:
        extra_defines.append("-DHAS_DATA_FILES")
    if has_test_harness:
        extra_defines.append("-DHAS_TEST_HARNESS")
    max_exec_ms = get_max_execution_duration(test_dir)
    if max_exec_ms > 0:
        extra_defines.append(f"-DMAX_EXECUTION_MS={max_exec_ms}")
    test_swf = test_dir / "test.swf"
    if test_swf.exists():
        import struct as struct_mod
        with open(test_swf, "rb") as swf_f:
            swf_header = swf_f.read(8)
        if len(swf_header) >= 8:
            swf_file_size = struct_mod.unpack("<I", swf_header[4:8])[0]
        else:
            swf_file_size = test_swf.stat().st_size
        extra_defines.append(f"-DSWF_FILE_SIZE={swf_file_size}")
    # Write SWF_URL to a header file instead of -D (avoids shell/response-file quoting issues)
    (build_dir / "swf_url.h").write_text('#define SWF_URL "file:///test.swf"\n')
    extra_defines.append("-include")
    extra_defines.append(str(build_dir / "swf_url.h"))

    # Source emsdk and compile with emcc
    if not EMSDK_ENV.exists():
        return False, f"emsdk not found at {EMSDK_ENV}"

    c_files = sorted(str(f) for f in build_dir.glob("*.c"))

    # Build emcc command as a list to avoid shell quoting issues with -D defines.
    # We source emsdk_env.sh first, then exec emcc.
    includes = [
        f"-I{build_dir}",
        f"-I{inc}", f"-I{inc}/actionmodern", f"-I{inc}/libswf", f"-I{inc}/memory",
        f"-I{SWFMODERN}/lib/c-hashmap",
    ]

    emcc_args = c_files + extra_defines + includes + [
        "-w", "-Wno-error=implicit-function-declaration",
        "-O2", "-include", "zlib.h",
        "-sWASM=1",
        "-sALLOW_MEMORY_GROWTH=1",
        "-sUSE_ZLIB=1",
        "-sNO_EXIT_RUNTIME=1",
    ]
    emcc_args += [
        "-sEXPORTED_FUNCTIONS=['_main','_runSWF']",
        "-sEXPORTED_RUNTIME_METHODS=['ccall','cwrap']",
        "-sINITIAL_MEMORY=16MB",
    ]
    emcc_args += ["-o", str(build_dir / "test.js")]
    # Write args to a response file to avoid shell escaping issues
    resp_file = build_dir / "emcc_args.txt"
    resp_file.write_text("\n".join(emcc_args))
    cmd = f"source {EMSDK_ENV} 2>/dev/null && emcc @{resp_file}"

    try:
        proc = subprocess.Popen(
            ["bash", "-c", cmd],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        )
        stdout, stderr = proc.communicate(timeout=300)
        return proc.returncode == 0, stderr.decode("utf-8", errors="replace")
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait()
        return False, "emcc compilation timed out"


def deploy_wasm(test_name, build_dir, deploy_dir):
    """Deploy WASM build to a directory with an HTML wrapper.

    Creates deploy_dir/<flat>/ with .js, .wasm, and index.html, where <flat>
    is `test_name` with any `/` separators replaced by `_` so nested test
    names like `bitmap_data_thorough/scroll` land in a single subdirectory.
    """
    flat_name = test_name.replace("/", "_")
    out_dir = deploy_dir / flat_name
    out_dir.mkdir(parents=True, exist_ok=True)

    # Copy WASM artifacts
    for ext in (".js", ".wasm"):
        src = build_dir / f"test{ext}"
        if src.exists():
            shutil.copy2(src, out_dir / f"{flat_name}{ext}")

    # Generate standalone HTML page
    html = f"""<!DOCTYPE html>
<html lang="en">
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1.0">
<title>SWFRecomp Demo - {test_name}</title>
<style>
* {{ margin: 0; padding: 0; box-sizing: border-box; }}
body {{ font-family: monospace; background: #1a1a1a; color: #e0e0e0; padding: 20px; }}
h1 {{ color: #4CAF50; margin-bottom: 10px; font-size: 1.3em; }}
#output {{ background: #111; border: 1px solid #333; border-radius: 8px;
           padding: 15px; white-space: pre-wrap; font-size: 14px;
           max-height: 80vh; overflow-y: auto; margin-top: 10px; }}
button {{ background: #4CAF50; color: white; border: none; padding: 8px 20px;
         border-radius: 4px; cursor: pointer; font-size: 14px; }}
button:hover {{ background: #45a049; }}
button:disabled {{ background: #555; cursor: default; }}
.info {{ color: #888; font-size: 0.9em; margin-bottom: 10px; }}
</style>
</head>
<body>
<h1>{test_name}</h1>
<p class="info">Recompiled SWF running in WebAssembly (trace output below)</p>
<button id="btn-run" disabled onclick="startDemo()">Run SWF</button>
<div id="output"></div>
<script>
var output = document.getElementById('output');
window.Module = {{
    locateFile: function(path) {{ return '{flat_name}/' + path.replace('test.', '{flat_name}.'); }},
    print: function(text) {{ output.textContent += text + '\\n'; }},
    printErr: function(text) {{ output.textContent += '[stderr] ' + text + '\\n'; }},
    onRuntimeInitialized: function() {{
        document.getElementById('btn-run').disabled = false;
        output.textContent = 'WASM module loaded. Click Run SWF.\\n';
    }}
}};
function startDemo() {{
    document.getElementById('btn-run').disabled = true;
    output.textContent = '';
    try {{ Module.ccall('runSWF', null, [], []); }}
    catch(e) {{ output.textContent += '\\nError: ' + e.message + '\\n'; }}
    output.textContent += '\\n=== done ===\\n';
}}
</script>
<script src="{flat_name}/{flat_name}.js"></script>
</body>
</html>"""
    (deploy_dir / f"{flat_name}.html").write_text(html)
    return True


def run_binary(build_dir, event_file=None, extra_env=None):
    """Run the compiled binary and capture output.

    Returns (stdout, returncode, stderr).
    """
    cmd = [str(build_dir / "test_run")]
    if event_file is not None:
        cmd.append(str(event_file))
    env = os.environ.copy()
    # Ruffle tests use a fixed UTC+5:45 (Nepal) timezone for determinism.
    # Use POSIX fixed-offset TZ to avoid historical tz transitions.
    env.setdefault("TZ", "NPT-5:45")
    if extra_env:
        env.update(extra_env)
    try:
        proc = subprocess.Popen(
            cmd,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            env=env,
        )
        stdout, stderr = proc.communicate(timeout=30)
        return (stdout.decode("utf-8", errors="replace"),
                proc.returncode,
                stderr.decode("utf-8", errors="replace"))
    except subprocess.TimeoutExpired:
        proc.kill()
        proc.wait()
        return None, -1, ""


def _diff_indices(actual, expected, epsilon=0.0, number_patterns=None):
    """Return the set of 0-based line indices where `actual` differs from
    `expected` after the same whitespace-stripping compare_output does.
    Used by the Ruffle-subset-match check to compare diff-sets line-wise."""
    actual_lines = actual.split("\n")
    expected_lines = expected.rstrip("\n").split("\n")
    for lines in (actual_lines, expected_lines):
        while lines and lines[0].strip() == "":
            lines.pop(0)
        while lines and lines[-1].strip() == "":
            lines.pop()
    n = max(len(actual_lines), len(expected_lines))
    return {
        i for i in range(n)
        if not _lines_approx_equal(
            actual_lines[i] if i < len(actual_lines) else "<missing>",
            expected_lines[i] if i < len(expected_lines) else "<missing>",
            epsilon,
            number_patterns,
        )
    }


def ruffle_subset_match(our_actual, flash_expected, ruffle_actual, epsilon=0.0, number_patterns=None):
    """Return True if our diffs against Flash's `output.txt` are a subset of
    Ruffle's diffs against the same file. The subset is taken over line
    indices, so at every line where we disagree with Flash, Ruffle also
    disagrees with Flash — i.e., we are no worse than Ruffle on this test.
    An empty our-diff set (we match Flash exactly) also qualifies."""
    our = _diff_indices(our_actual, flash_expected, epsilon, number_patterns)
    ruffle = _diff_indices(ruffle_actual, flash_expected, epsilon, number_patterns)
    return our.issubset(ruffle), len(our), len(ruffle)


def _test_is_known_failure(test_dir):
    """Return True if test.toml sets `known_failure = true` at the top level.
    Uses tomllib (3.11+) so parsing matches the existing toml usage."""
    toml_path = test_dir / "test.toml"
    if not toml_path.is_file():
        return False
    try:
        import tomllib
        with open(toml_path, "rb") as f:
            data = tomllib.load(f)
    except Exception:
        return False
    return bool(data.get("known_failure"))


def compare_output(actual, expected, epsilon=0.0, number_patterns=None):
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
            number_patterns,
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
        if not _lines_approx_equal(a, e, epsilon, number_patterns):
            mismatches += 1
            if mismatches <= 3:
                diff.append(f"  line {i+1}: got {a!r}, expected {e!r}")

    total_mismatches = max_lines - matching
    summary = f"{total_mismatches} line(s) differ (actual={len(actual_lines)}, expected={len(expected_lines)})"
    if diff:
        summary += "\n" + "\n".join(diff)
    return False, summary, line_stats


def format_diff(actual, expected, context=3, epsilon=0.0, number_patterns=None):
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

        if _lines_approx_equal(a if a is not None else "", e if e is not None else "", epsilon, number_patterns):
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
        "ruffle_matched": stats.get("ruffle_matched", 0),
        "fail": total - stats["pass"] - stats.get("ruffle_matched", 0),
        "pass_rate": round(100 * stats["pass"] / total, 1) if total else 0,
        "effective_pass": stats["pass"] + stats.get("ruffle_matched", 0),
        "effective_pass_rate": round(
            100 * (stats["pass"] + stats.get("ruffle_matched", 0)) / total, 1
        ) if total else 0,
        "breakdown": {
            k: stats[k]
            for k in ["output_mismatch", "compile_fail", "recomp_fail",
                       "runtime_segfault", "runtime_error", "timeout",
                       "ruffle_matched"]
            if stats.get(k)
        },
        "tests": test_results,
    }


def write_json(report, path):
    """Write report dict to a JSON file."""
    with open(path, "w") as f:
        json.dump(report, f, indent=2)


def merge_results(existing_path, new_report):
    """Merge new_report into existing JSON results, updating tests by name.

    Tests from new_report replace any existing entries with the same name.
    Tests in the existing file that aren't in new_report are preserved.
    Summary stats are recomputed from the merged test list.
    """
    with open(existing_path) as f:
        existing = json.load(f)

    # Build dict of existing tests keyed by name
    merged = {t["test"]: t for t in existing.get("tests", [])}

    # Overlay new results
    for t in new_report.get("tests", []):
        merged[t["test"]] = t

    # Rebuild test list sorted by name
    all_tests = sorted(merged.values(), key=lambda t: t["test"])

    # Recompute stats
    pass_count = sum(1 for t in all_tests if t["status"] == "pass")
    ruffle_matched_count = sum(1 for t in all_tests if t["status"] == "ruffle_matched")
    total = len(all_tests)
    breakdown = Counter()
    for t in all_tests:
        s = t["status"]
        if s not in ("pass", "ruffle_matched"):
            # Map status to breakdown category
            cat = {"fail": "output_mismatch", "output_mismatch": "output_mismatch",
                   "segfault": "runtime_segfault", "runtime_segfault": "runtime_segfault",
                   "compile_fail": "compile_fail", "recomp_fail": "recomp_fail",
                   "runtime_error": "runtime_error", "timeout": "timeout"}.get(s, s)
            breakdown[cat] += 1
    if ruffle_matched_count:
        breakdown["ruffle_matched"] = ruffle_matched_count

    result = {
        "metadata": new_report.get("metadata", existing.get("metadata", {})),
        "total": total,
        "pass": pass_count,
        "ruffle_matched": ruffle_matched_count,
        "fail": total - pass_count - ruffle_matched_count,
        "pass_rate": round(100 * pass_count / total, 1) if total else 0,
        "effective_pass": pass_count + ruffle_matched_count,
        "effective_pass_rate": round(
            100 * (pass_count + ruffle_matched_count) / total, 1
        ) if total else 0,
        "breakdown": {k: v for k, v in breakdown.items() if v},
        "tests": all_tests,
    }
    return result


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
  %(prog)s --diff --count=50         Run first 50 tests, show diffs for failures
  %(prog)s --start=100 --count=50   Run 50 tests starting from index 100
  %(prog)s --json=results.json      Write JSON report
  %(prog)s --shard=1/4              Run first quarter of tests (for CI)
""",
    )
    parser.add_argument(
        "--tests-dir", metavar="DIR",
        help="Directory containing test subdirectories (default: tests/swfs/avm1)")
    parser.add_argument(
        "--test", metavar="NAME", action="append",
        help="Run specific test(s) by name (repeatable, e.g. --test=foo --test=bar)")
    parser.add_argument(
        "--exclude", metavar="NAME", action="append",
        help="Exclude specific test(s) by name (repeatable, e.g. --exclude=foo --exclude=bar)")
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
        "--start", type=int, default=0, metavar="N",
        help="Start from test index N (0-based, into sorted test list; default: 0)")
    parser.add_argument(
        "--count", type=int, metavar="N",
        help="Run N tests starting from --start index")
    parser.add_argument(
        "--limit", type=int, metavar="N",
        help="Only run the first N tests (equivalent to --count)")
    parser.add_argument(
        "--shard", metavar="I/N",
        help="Run shard I of N (1-based, for CI parallelism)")
    parser.add_argument(
        "--json", metavar="PATH",
        help="Write JSON results report to PATH")
    parser.add_argument(
        "--mode", choices=["no-graphics", "graphics", "graphics-headless-legacy"],
        default=None,
        help="Build mode. Default 'no-graphics' (swf_core.c, no rendering). "
             "'graphics' is the new full-graphics-native mode (swf.c + offscreen Dawn). "
             "'graphics-headless-legacy' is the legacy headless mode (swf_headless.c + offscreen Dawn).")
    parser.add_argument(
        "--headless", action="store_true",
        help="DEPRECATED alias for --mode=graphics-headless-legacy.")
    parser.add_argument(
        "--append", action="store_true",
        help="Append to existing JSON results instead of overwriting (merge by test name)")
    parser.add_argument(
        "--resume", action="store_true",
        help="Skip tests already in the results file and append new results (implies --append)")
    parser.add_argument(
        "--auto-start", action="store_true",
        help="Start from the first test with no results in the results file (implies --append)")
    parser.add_argument(
        "--asan", action="store_true",
        help="Compile with AddressSanitizer (-fsanitize=address -g -O1) for crash debugging")
    parser.add_argument(
        "--no-ccache", action="store_true",
        help="Disable ccache even if installed (forces full recompile of every source)")
    parser.add_argument(
        "--save-actual", metavar="PATH",
        help="Save the actual output of the first test to PATH (for generating expected output files)")
    parser.add_argument(
        "--expected-suffix", metavar="SUFFIX",
        help="Use output.SUFFIX.txt instead of output.txt for expected output "
             "(e.g. --expected-suffix=flash uses output.flash.txt). "
             "Only tests that have the alternate file are included.")
    parser.add_argument(
        "--wasm", action="store_true",
        help="Build WASM instead of native (requires emsdk). Implies --deploy if --deploy-dir given.")
    parser.add_argument(
        "--deploy-dir", metavar="DIR",
        help="Deploy WASM builds to DIR (e.g. docs/injector). Used with --wasm.")
    return parser.parse_args()


def _fmt_phases(pt):
    if not pt:
        return ""
    parts = []
    for k, label in (("recomp", "r"), ("compile", "c"), ("run", "x")):
        if k in pt:
            parts.append(f"{label}={pt[k]:.2f}s")
    return f" [{' '.join(parts)}]" if parts else ""


def main():
    global TESTS_DIR, RESULTS_DIR, RESULTS_FINAL, RESULTS_PREVIOUS, RESULTS_CURRENT
    args = parse_args()

    # Resolve mode from --mode (preferred) and the deprecated --headless alias.
    if args.mode is None:
        args.mode = "graphics-headless-legacy" if args.headless else "no-graphics"
    elif args.headless and args.mode != "graphics-headless-legacy":
        print(f"Warning: --headless ignored because --mode={args.mode} was also given",
              file=sys.stderr)
    # Legacy boolean kept in sync so existing call sites still work.
    args.headless = (args.mode == "graphics-headless-legacy")
    args.uses_dawn = args.mode in ("graphics", "graphics-headless-legacy")

    # Determine expected output filename
    expected_filename = f"output.{args.expected_suffix}.txt" if args.expected_suffix else "output.txt"

    # Override tests directory if specified
    if args.tests_dir:
        TESTS_DIR = Path(args.tests_dir).resolve()
        if not TESTS_DIR.is_dir():
            print(f"Error: tests directory not found: {TESTS_DIR}")
            sys.exit(1)

    # Re-derive results paths from TESTS_DIR
    RESULTS_DIR = TESTS_DIR / "_results"
    if args.expected_suffix:
        # Use separate results files for alternate expected output
        RESULTS_FINAL = RESULTS_DIR / f"results_{args.expected_suffix}.json"
        RESULTS_PREVIOUS = RESULTS_DIR / f"results_{args.expected_suffix}_previous.json"
        RESULTS_CURRENT = RESULTS_DIR / f"results_{args.expected_suffix}_current.json"
    else:
        RESULTS_FINAL = RESULTS_DIR / "results.json"
        RESULTS_PREVIOUS = RESULTS_DIR / "results_previous.json"
        RESULTS_CURRENT = RESULTS_DIR / "results_current.json"

    if not RECOMP_BIN.exists():
        print(f"Error: SWFRecomp not found at {RECOMP_BIN}")
        print(f"Build it first:  cd {PROJECT_ROOT}/SWFRecomp/build && cmake .. && make -j")
        sys.exit(1)

    if args.uses_dawn:
        dawn_lib = DAWN_INSTALL / "lib" / "libwebgpu_dawn.a"
        if not dawn_lib.exists():
            print(f"Error: Dawn library not found at {dawn_lib}")
            print(f"Build Dawn first and install to {DAWN_INSTALL}")
            sys.exit(1)

    # Determine test list. Walks the tree recursively so nested tests like
    # `bitmap_data_thorough/scroll` are discovered alongside flat tests; test
    # names are forward-slashed relative paths under TESTS_DIR.
    if args.test:
        import fnmatch
        all_tests = discover_tests(TESTS_DIR, expected_filename)
        tests = []
        for t in args.test:
            if '*' in t or '?' in t:
                matched = fnmatch.filter(all_tests, t)
                if not matched:
                    print(f"Warning: no tests match pattern '{t}'")
                tests.extend(matched)
            else:
                test_dir = TESTS_DIR / t
                if not test_dir.is_dir():
                    print(f"Error: test directory not found: {test_dir}")
                    sys.exit(1)
                tests.append(t)
        tests = sorted(set(tests))
    else:
        tests = discover_tests(TESTS_DIR, expected_filename)

    # Apply --exclude filter
    if args.exclude:
        exclude_set = set(args.exclude)
        tests = [t for t in tests if t not in exclude_set]

    total_available = len(tests)

    # Slice by start index and count
    count = args.count or args.limit
    if args.start or count:
        end = args.start + count if count else None
        tests = tests[args.start:end]

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

    # Ensure results directory exists
    RESULTS_DIR.mkdir(parents=True, exist_ok=True)

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

    # Determine json_path early so --append can write incrementally
    json_path = args.json
    if json_path is None and args.mode == "graphics-headless-legacy":
        json_path = str(RESULTS_DIR / "results_headless.json")
    elif json_path is None and args.mode == "graphics":
        json_path = str(RESULTS_DIR / "results_graphics.json")
    if json_path is None and not args.test:
        json_path = str(RESULTS_FINAL)

    # --auto-start: start from the first test with no results
    if args.auto_start:
        args.append = True
        if json_path and Path(json_path).exists():
            with open(json_path) as f:
                existing = json.load(f)
            already_done = {t["test"] for t in existing.get("tests", [])}
            first_missing = next((i for i, t in enumerate(tests) if t not in already_done), len(tests))
            if first_missing > 0:
                print(f"Auto-start: skipping to index {first_missing} ({tests[first_missing] if first_missing < len(tests) else 'end'}), {len(tests) - first_missing} tests remaining")
                tests = tests[first_missing:]

    # --resume: skip tests already present in the results file
    if args.resume:
        args.append = True
        if json_path and Path(json_path).exists():
            with open(json_path) as f:
                existing = json.load(f)
            already_done = {t["test"] for t in existing.get("tests", [])}
            before = len(tests)
            tests = [t for t in tests if t not in already_done]
            skipped = before - len(tests)
            if skipped:
                print(f"Resuming: skipped {skipped} already-completed tests, {len(tests)} remaining")

    def save_incremental():
        """Write current results to results_current.json and run diff."""
        if not incremental:
            return
        completed = len(test_results)
        report = build_report(test_results, stats, completed, total_available, run_start)
        write_json(report, RESULTS_CURRENT)
        run_diff_comparison(RESULTS_CURRENT, partial=True)
        # In --append mode, also merge into the target file after each test
        if args.append and json_path and Path(json_path).exists():
            merged = merge_results(json_path, report)
            write_json(merged, json_path)

    json_written = False  # Track whether final JSON was written successfully

    def write_partial_on_exit():
        """Write partial results if the test run was interrupted before final write."""
        if json_written or not json_path or not test_results:
            return
        try:
            report = build_report(test_results, stats, len(test_results), total_available, run_start)
            report["metadata"]["partial"] = True
            report["metadata"]["interrupted"] = True
            write_json(report, json_path)
            print(f"\nPartial results ({len(test_results)} tests) written to {json_path}", file=sys.stderr)
        except Exception:
            pass  # Best effort — don't mask the original error

    atexit.register(write_partial_on_exit)

    for i, name in enumerate(tests):
      try:
        test_dir = TESTS_DIR / name
        epsilon = get_epsilon(test_dir)
        number_patterns = get_number_patterns(test_dir)
        if args.verbose:
            print(f"[{i+1}/{len(tests)}] {name}...", end=" ", flush=True)

        test_start = time.monotonic()
        entry = {"test": name}
        phase_times = {}
        entry["phases"] = phase_times
        image_comparisons = {}
        image_results = {}

        # Step 1: Recompile SWF
        _t = time.perf_counter()
        recomp_ok, recomp_stderr = recompile_swf(test_dir, force=args.recompile)
        phase_times["recomp"] = round(time.perf_counter() - _t, 3)
        if not recomp_ok:
            stats["recomp_fail"] += 1
            fail_list.append(name)
            fail_details[name] = "SWFRecomp failed"
            entry.update(status="recomp_fail", detail="SWFRecomp failed",
                         duration=round(time.monotonic() - test_start, 2))
            test_results.append(entry)
            if args.verbose:
                print("RECOMP_FAIL" + _fmt_phases(phase_times))
                if recomp_stderr.strip():
                    for line in recomp_stderr.strip().splitlines()[:10]:
                        print(f"  stderr: {line}")
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
            # Parse image comparisons early so we can enable rendering at compile time
            image_comparisons = parse_image_comparisons(test_dir) if args.uses_dawn else {}
            has_image_cmps = bool(image_comparisons) and HAS_PIL
            _t = time.perf_counter()
            if args.wasm:
                ok, err = compile_wasm(test_dir, num_frames, build_dir)
            else:
                ok, err = compile_native(test_dir, num_frames, build_dir,
                                         mode=args.mode,
                                         has_image_comparisons=has_image_cmps,
                                         asan=args.asan,
                                         use_ccache=not args.no_ccache)
            phase_times["compile"] = round(time.perf_counter() - _t, 3)
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
                    print("COMPILE_FAIL" + _fmt_phases(phase_times))
                    print(f"  Error: {detail}")
                save_incremental()
                continue

            # Step 3: Run binary (skip for WASM builds — deploy only)
            if args.wasm:
                entry.update(status="wasm_built",
                             duration=round(time.monotonic() - test_start, 2))
                if args.deploy_dir:
                    deploy_dir = Path(args.deploy_dir)
                    deploy_wasm(name, build_dir, deploy_dir)
                    if args.verbose:
                        print(f"WASM_BUILT → deployed to {deploy_dir}/{name}/")
                else:
                    if args.verbose:
                        print(f"WASM_BUILT ({build_dir})")
                stats["pass"] += 1
                test_results.append(entry)
                save_incremental()
                continue

            # Set up capture triggers for image comparison tests
            run_env = {}
            if has_image_cmps and args.uses_dawn:
                triggers = []
                for cmp_name, cmp_config in image_comparisons.items():
                    trig = cmp_config["trigger"]
                    if trig[0] == "last_frame":
                        triggers.append(f"{cmp_name}:last_frame")
                    elif trig[0] == "specific_iteration":
                        triggers.append(f"{cmp_name}:iteration:{trig[1]}")
                    elif trig[0] == "fs_command":
                        triggers.append(f"{cmp_name}:fs_command")
                run_env["CAPTURE_TRIGGERS"] = ",".join(triggers)
                run_env["CAPTURE_OUTPUT_DIR"] = str(build_dir)
                # Force lavapipe software Vulkan for WSL2 compatibility
                run_env["VK_ICD_FILENAMES"] = "/usr/share/vulkan/icd.d/lvp_icd.json"
                run_env["VK_DRIVER_FILES"] = "/usr/share/vulkan/icd.d/lvp_icd.json"
            _t = time.perf_counter()
            raw_output, rc, run_stderr = run_binary(build_dir, event_file=event_file,
                                                    extra_env=run_env if run_env else None)
            phase_times["run"] = round(time.perf_counter() - _t, 3)
            if raw_output is None:
                stats["timeout"] += 1
                fail_list.append(name)
                fail_details[name] = "runtime timeout"
                entry.update(status="timeout", detail="runtime timeout (>10s)",
                             duration=round(time.monotonic() - test_start, 2))
                test_results.append(entry)
                if args.verbose:
                    print("TIMEOUT" + _fmt_phases(phase_times))
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
                    crash_expected = (test_dir / expected_filename).read_text(encoding="utf-8", errors="replace").replace("\r\n", "\n").rstrip("\n")
                    crash_match, crash_diff, crash_line_stats = compare_output(crash_actual, crash_expected, epsilon, number_patterns)
                    entry["lines"] = crash_line_stats
                    if crash_match:
                        entry["detail"] += " (output matches)"
                    if args.diff:
                        fail_diffs[name] = format_diff(crash_actual, crash_expected, epsilon=epsilon, number_patterns=number_patterns)
                test_results.append(entry)
                if args.verbose:
                    line_info = ""
                    if "lines" in entry:
                        ls = entry["lines"]
                        line_info = f" [{ls.get('matched',0)}/{ls.get('expected',0)} lines]"
                    print(f"{crash_status.upper()}{line_info}" + _fmt_phases(phase_times))
                    if run_stderr.strip():
                        max_stderr = 100 if args.asan else 20
                        for line in run_stderr.strip().splitlines()[:max_stderr]:
                            print(f"  stderr: {line}")
                save_incremental()
                continue

            # Step 3b: Image comparisons (only when rendering is enabled)
            # image_comparisons was already parsed before compile when uses_dawn
            if not args.uses_dawn:
                image_comparisons = {}
            elif not image_comparisons:
                image_comparisons = parse_image_comparisons(test_dir)
            image_results = {}
            if image_comparisons and HAS_PIL:
                for cmp_name, cmp_config in image_comparisons.items():
                    # Look for expected PNG: local test dir first, then Ruffle upstream
                    expected_png = test_dir / f"{cmp_name}.expected.png"
                    if not expected_png.exists() and RUFFLE_UPSTREAM.exists():
                        upstream_png = RUFFLE_UPSTREAM / name / f"{cmp_name}.expected.png"
                        if upstream_png.exists():
                            expected_png = upstream_png
                    # Actual PNG: look in build_dir (produced by test binary)
                    actual_png = build_dir / f"{cmp_name}.png"
                    if not expected_png.exists():
                        image_results[cmp_name] = {
                            "status": "skip",
                            "message": f"No expected image: {cmp_name}.expected.png",
                        }
                        continue
                    if not actual_png.exists():
                        image_results[cmp_name] = {
                            "status": "fail",
                            "message": f"No actual image produced for {cmp_name}",
                        }
                        continue
                    passed, message, max_diff = compare_images(
                        actual_png, expected_png, cmp_config["checks"])
                    image_results[cmp_name] = {
                        "status": "pass" if passed else "fail",
                        "message": message,
                        "max_diff": max_diff,
                        "trigger": cmp_config["trigger"],
                        "known_failure": cmp_config.get("known_failure", False),
                    }
                    # Save actual and difference images to test dir for inspection
                    if args.verbose:
                        saved_actual = test_dir / f"{cmp_name}.actual.png"
                        shutil.copy2(str(actual_png), str(saved_actual))
                        diff_in_build = actual_png.parent / (actual_png.stem + ".difference.png")
                        if diff_in_build.exists():
                            saved_diff = test_dir / f"{cmp_name}.difference.png"
                            shutil.copy2(str(diff_in_build), str(saved_diff))

        # Step 4: Filter and compare trace output
        actual = filter_output(raw_output)
        if args.save_actual and actual:
            Path(args.save_actual).write_text(actual + "\n", encoding="utf-8")
            print(f"  Saved actual output ({len(actual.splitlines())} lines) to {args.save_actual}")
            args.save_actual = None  # only save once
        expected = (test_dir / expected_filename).read_text(encoding="utf-8", errors="replace").replace("\r\n", "\n").rstrip("\n")

        match, diff_summary, line_stats = compare_output(actual, expected, epsilon, number_patterns)
        entry["lines"] = line_stats
        entry["duration"] = round(time.monotonic() - test_start, 2)

        # Include image comparison results in entry if any were run
        if image_comparisons:
            entry["image_comparisons"] = image_results
            # Log image comparison results in verbose mode
            if args.verbose and image_results:
                for cmp_name, cmp_result in image_results.items():
                    status = cmp_result["status"].upper()
                    msg = cmp_result.get("message", "")
                    print(f"    [image:{cmp_name}] {status} - {msg}")

        if match:
            stats["pass"] += 1
            pass_list.append(name)
            entry["status"] = "pass"
            test_results.append(entry)
            if args.verbose:
                print("PASS" + _fmt_phases(phase_times))
        else:
            # Before reporting output_mismatch, check if this is a test Ruffle
            # itself marks as known_failure (ships output.ruffle.txt alongside
            # the Flash-generated output.txt). If so, and our diff lines are
            # a subset of Ruffle's diff lines against the same output.txt,
            # promote to `ruffle_matched` — we're doing at least as well as
            # Ruffle, which is the reference implementation for AVM1.
            ruffle_actual_path = test_dir / "output.ruffle.txt"
            ruffle_matched = False
            if (ruffle_actual_path.is_file()
                    and _test_is_known_failure(test_dir)):
                try:
                    ruffle_actual = (
                        ruffle_actual_path
                        .read_text(encoding="utf-8", errors="replace")
                        .replace("\r\n", "\n")
                        .rstrip("\n")
                    )
                    is_subset, ours, theirs = ruffle_subset_match(
                        actual, expected, ruffle_actual, epsilon, number_patterns)
                    if is_subset:
                        ruffle_matched = True
                        entry["ruffle_diff_count"] = theirs
                        entry["ours_diff_count"] = ours
                except Exception:
                    pass  # fall through to output_mismatch

            if ruffle_matched:
                stats["ruffle_matched"] = stats.get("ruffle_matched", 0) + 1
                pass_list.append(name)
                entry["status"] = "ruffle_matched"
                entry["detail"] = (
                    f"diffs {entry['ours_diff_count']} ⊆ ruffle {entry['ruffle_diff_count']}"
                )
                test_results.append(entry)
                if args.verbose:
                    print("RUFFLE_MATCHED" + _fmt_phases(phase_times))
            else:
                stats["output_mismatch"] += 1
                fail_list.append(name)
                fail_details[name] = diff_summary
                if args.diff:
                    fail_diffs[name] = format_diff(actual, expected, epsilon=epsilon, number_patterns=number_patterns)
                entry["status"] = "output_mismatch"
                entry["detail"] = diff_summary.split("\n")[0]  # first line only
                actual_snip, expected_snip = snippet_around_mismatch(actual, expected)
                entry["actual_output"] = actual_snip
                entry["expected_output"] = expected_snip
                test_results.append(entry)
                if args.verbose:
                    print("MISMATCH" + _fmt_phases(phase_times))
                    if run_stderr.strip():
                        for line in run_stderr.strip().splitlines()[:200]:
                            print(f"  stderr: {line}")
        save_incremental()
      except Exception as exc:
        # Catch unexpected errors so one bad test doesn't abort the entire shard
        print(f"\nERROR: test '{name}' raised {type(exc).__name__}: {exc}", file=sys.stderr)
        entry = {"test": name, "status": "runtime_error",
                 "detail": f"runner exception: {type(exc).__name__}: {exc}"}
        test_results.append(entry)
        stats["runtime_error"] = stats.get("runtime_error", 0) + 1
        fail_list.append(name)
        fail_details[name] = f"runner exception: {exc}"
        save_incremental()

    # Print results
    total = len(tests)
    pass_count = stats["pass"]
    ruffle_matched_count = stats.get("ruffle_matched", 0)
    effective_pass = pass_count + ruffle_matched_count
    print(f"\n{'='*60}")
    print(f"Total tests:     {total}")
    if total:
        print(f"Pass:            {pass_count} ({100*pass_count/total:.1f}%)")
        if ruffle_matched_count:
            print(f"Ruffle-matched:  {ruffle_matched_count}"
                  f" ({100*ruffle_matched_count/total:.1f}%)")
            print(f"Effective pass:  {effective_pass}"
                  f" ({100*effective_pass/total:.1f}%)")
    print(f"Fail:            {total - effective_pass}")
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

    # Write final JSON results (json_path already computed above)
    if json_path:
        report = build_report(test_results, stats, total, total_available, run_start)
        if args.append and Path(json_path).exists():
            report = merge_results(json_path, report)
            print(f"\nMerged {len(test_results)} results into {json_path} ({report['total']} total)")
        write_json(report, json_path)
        json_written = True
        print(f"Results written to {json_path}")

        # Run final diff comparison (non-partial)
        if not args.test and not args.append:
            print("\nFinal diff vs previous results:")
            run_diff_comparison(json_path, partial=False)


if __name__ == "__main__":
    main()
