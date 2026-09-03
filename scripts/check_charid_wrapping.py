#!/usr/bin/env python3
"""Completeness oracle for the recompiler's CHARID() character-id wrapper.

WHY THIS EXISTS
---------------
A loaded child SWF's character ids have to be re-based so they cannot collide
with the parent's dictionary. `generate_child_movie_file`
(`ruffle-tests/verify_output.py`) used to do that with ONE `re.sub` per emitted
call name — a hand-maintained list. Any char-id-carrying emission the list did
not name kept its RAW id and silently disagreed with every emission that was
offset, and the failure mode is a lookup that finds nothing rather than a
crash.

The recompiler now wraps every character id it emits in `CHARID(...)` (an
identity macro, `SWFModernRuntime/include/libswf/tag.h`), so the harness does
one value-keyed substitution. That is only an improvement if a MISSED emission
site is detectable rather than merely less likely — otherwise the regex list
has just been traded for a hand-maintained set of wrapped call sites. This
script is that detector.

WHAT IT CHECKS
--------------
Both halves of the problem, with the argument positions and struct field
indices DERIVED from the runtime headers rather than restated here:

1. **Call arguments.** Every prototype in `tag.h` whose parameter list names a
   parameter in CHARID_PARAM_NAMES contributes (function, arg index) pairs. In
   the generated C, an argument at one of those positions must not be a bare
   integer literal.

2. **Data-table fields.** Every `typedef struct { ... } Name;` in the scanned
   headers whose fields name one in CHARID_PARAM_NAMES contributes (type,
   field index) pairs. Positional initialisers of that type in the generated C
   (`Name foo[] = { { a, b, ... }, ... };`) must not hold a bare integer
   literal at one of those indices. This is the half the old call-name-keyed
   scheme could not see at all: `FramePlacement.char_id` is a struct field, and
   a child sprite's loop-back placement table described its objects by RAW ids
   while the objects themselves were placed under OFFSET ids.

A bare `0` is an offender like any other value, so the rule has no exceptions
and the sentinel arrays get wrapped too. `0` is NOT a character id — it is the
"no character" sentinel in every one of these positions (a PlaceObject2 /
FramePlacement with `char_id == 0` is a Modify tag; `tagDefineButton`'s
`hit_char_id == 0` means no hit shape) — but that is the *consumer's* problem,
not the wrapper's: `generate_child_movie_file` skips `CHARID(0)` when it
offsets, with the reasoning at that call site.

TWO MODES, AND WHY BOTH
-----------------------
`--emitter` reads `SWFRecomp/src/swf.cpp` and enumerates the complete set of
char-id CALLS the recompiler emits, so no sample can hide one — but it cannot
see a struct-initialiser row, which is a plain string literal rather than a
call. The default (generated-C) mode sees struct rows, but only for whatever
the SWFs it is pointed at happen to emit. Each caught a real miss the other
was blind to when this wrapper was introduced. Run both.

USAGE
-----
    # one generated tree, or any set of generated .c/.h files
    scripts/check_charid_wrapping.py path/to/RecompiledTags/tagMain.c
    scripts/check_charid_wrapping.py --tree path/to/build_dir

    # every char-id call the recompiler emits must go through charId()
    scripts/check_charid_wrapping.py --emitter

    # what the headers say the char-id positions are (no files needed)
    scripts/check_charid_wrapping.py --list-positions

Exit status 0 = clean, 1 = offenders found (printed one per line), 2 = usage.

`verify_output.py` imports `check_text` from here and hard-fails
`generate_child_movie_file` on any offender, so a missed emission site cannot
reach a multi-SWF test as a silent id disagreement.
"""
import argparse
import re
import sys
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parent.parent

# Parameter / field names that hold a CHARACTER id (an index into the runtime
# `dictionary`). Deliberately a whitelist and not a `_id$` pattern: tag.h is
# full of ids that are NOT character ids and must NOT be offset —
# `transform_id`, `cxform_id`, `codec_id`, `movie_id`, `clip_depth`,
# `glyph_base`, `frame_idx`.
CHARID_PARAM_NAMES = frozenset({
    "char_id",        # the common case
    "sprite_id",      # tagSetSpritePlacements
    "font_id",        # DefineFont* — fonts share the character id space
    "sound_id",       # tagDefineSound / tagStartSound
    "text_id",        # tagCSMTextSettings
    "hit_char_id",    # tagDefineButton's hit-test shape
    "local_char_id",  # tagImportCharacter
})

# Headers scanned for prototypes and struct definitions.
HEADERS = (
    "SWFModernRuntime/include/libswf/tag.h",
    "SWFModernRuntime/include/actionmodern/sprite_frame_scripts.h",
)

_BARE_INT = re.compile(r'^\(*\s*-?\d+\s*\)*$')
_IDENT = re.compile(r'[A-Za-z_]\w*$')


# One pass over the four things whose contents must not be scanned: a line
# comment, a block comment, a string literal and a char literal. Comments are
# blanked (newlines kept, so reported line numbers stay right); literals are
# left alone so the argument splitter still sees them as one token.
_TOKENS = re.compile(r"""//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"|'(?:\\.|[^'\\])*'""",
                     re.S)


def _blank(m):
    s = m.group(0)
    if s[0] in '"\'':
        return s
    return re.sub(r'[^\n]', ' ', s)


def _strip_comments(text):
    """Blank out // and /* */ comments, preserving offsets and newlines."""
    return _TOKENS.sub(_blank, text)


def _split_top_level(s):
    """Split on top-level commas, respecting (), [], {} and string literals."""
    parts, depth, buf, i, n = [], 0, [], 0, len(s)
    while i < n:
        c = s[i]
        if c in '"\'':
            j = i + 1
            while j < n and s[j] != c:
                j += 2 if s[j] == '\\' else 1
            buf.append(s[i:min(j + 1, n)])
            i = min(j + 1, n)
            continue
        if c in '([{':
            depth += 1
        elif c in ')]}':
            depth -= 1
        if c == ',' and depth == 0:
            parts.append(''.join(buf))
            buf = []
        else:
            buf.append(c)
        i += 1
    parts.append(''.join(buf))
    return [p.strip() for p in parts]


def _match_paren(text, open_idx):
    """Index of the ) matching the ( at open_idx, or -1."""
    depth, i, n = 0, open_idx, len(text)
    while i < n:
        c = text[i]
        if c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            i = min(j + 1, n)
            continue
        if c == '(':
            depth += 1
        elif c == ')':
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


def _match_brace(text, open_idx):
    depth, i, n = 0, open_idx, len(text)
    while i < n:
        c = text[i]
        if c in '"\'':
            j = i + 1
            while j < n and text[j] != c:
                j += 2 if text[j] == '\\' else 1
            i = min(j + 1, n)
            continue
        if c == '{':
            depth += 1
        elif c == '}':
            depth -= 1
            if depth == 0:
                return i
        i += 1
    return -1


def _param_name(decl):
    """Last identifier of a C parameter declaration, or None."""
    decl = decl.replace('[', ' ').replace(']', ' ').strip()
    m = _IDENT.search(decl)
    return m.group(0) if m else None


def load_positions(headers=None):
    """Derive the char-id positions from the runtime headers.

    Returns (calls, structs):
        calls   {function_name: frozenset(arg_index)}
        structs {type_name:    frozenset(field_index)}
    """
    calls, structs = {}, {}
    for rel in (headers or HEADERS):
        path = PROJECT_ROOT / rel
        if not path.exists():
            continue
        src = _strip_comments(path.read_text(encoding='utf-8', errors='replace'))

        # Function prototypes: `... name(params);`
        for m in re.finditer(r'\b([A-Za-z_]\w*)\s*\(', src):
            name = m.group(1)
            open_idx = m.end() - 1
            close = _match_paren(src, open_idx)
            if close < 0:
                continue
            tail = src[close + 1:close + 3].lstrip()
            if not tail.startswith(';'):
                continue          # not a prototype (a macro body, a call, ...)
            params = src[open_idx + 1:close]
            idxs = {i for i, d in enumerate(_split_top_level(params))
                    if _param_name(d) in CHARID_PARAM_NAMES}
            if idxs:
                calls.setdefault(name, set()).update(idxs)

        # Struct typedefs: `typedef struct [Tag] { fields } Name;`
        for m in re.finditer(r'\btypedef\s+struct\b[^{;]*\{', src):
            close = _match_brace(src, m.end() - 1)
            if close < 0:
                continue
            after = re.match(r'\s*([A-Za-z_]\w*)\s*;', src[close + 1:])
            if not after:
                continue
            fields = [f.strip() for f in src[m.end():close].split(';')]
            idxs, i = set(), 0
            for f in fields:
                if not f:
                    continue
                # `u16 a, b;` declares two fields.
                for d in _split_top_level(f):
                    if not d:
                        continue
                    if _param_name(d) in CHARID_PARAM_NAMES:
                        idxs.add(i)
                    i += 1
            if idxs:
                structs.setdefault(after.group(1), set()).update(idxs)

    # Function-like macro aliases. tag.h reaches tagDefineSpriteEx through
    # `tagDefineSprite` (a variadic arity-dispatch macro over
    # tagDefineSprite_4/_5), and the recompiler emits the MACRO name — so
    # without this the oracle would be blind to every tagDefineSprite call.
    # Resolved mechanically to a fixpoint rather than listed: a positional
    # forwarder inherits the callee's char-id index at the position of the
    # forwarded parameter, and a variadic macro that passes __VA_ARGS__
    # through inherits its callees' indices directly.
    for rel in (headers or HEADERS):
        path = PROJECT_ROOT / rel
        if not path.exists():
            continue
        src = _strip_comments(path.read_text(encoding='utf-8', errors='replace'))
        macros = {}
        for m in re.finditer(r'^[ \t]*#\s*define\s+([A-Za-z_]\w*)\(', src,
                             re.MULTILINE):
            open_idx = m.end() - 1
            close = _match_paren(src, open_idx)
            if close < 0:
                continue
            eol = src.find('\n', close)
            eol = len(src) if eol < 0 else eol
            params = [d.strip() for d in _split_top_level(src[open_idx + 1:close])]
            macros[m.group(1)] = (params, src[close + 1:eol])

        for _pass in range(len(macros) + 1):
            changed = False
            for name, (params, body) in macros.items():
                variadic = '...' in params
                idxs = set(calls.get(name, ()))
                for callee in set(re.findall(r'\b[A-Za-z_]\w*\b', body)):
                    if callee == name or callee not in calls:
                        continue
                    if variadic and '__VA_ARGS__' in body:
                        idxs |= calls[callee]
                        continue
                    for cm in re.finditer(r'\b%s\s*\(' % re.escape(callee), body):
                        cclose = _match_paren(body, cm.end() - 1)
                        if cclose < 0:
                            continue
                        cargs = _split_top_level(body[cm.end():cclose])
                        for ci in calls[callee]:
                            if ci < len(cargs) and cargs[ci] in params:
                                idxs.add(params.index(cargs[ci]))
                if idxs and idxs != set(calls.get(name, ())):
                    calls.setdefault(name, set()).update(idxs)
                    changed = True
            if not changed:
                break

    return ({k: frozenset(v) for k, v in calls.items()},
            {k: frozenset(v) for k, v in structs.items()})


def _line_of(text, idx):
    return text.count('\n', 0, idx) + 1


def check_text(text, label="<text>", positions=None):
    """Check one generated-C blob. Returns (ok, [problem strings])."""
    calls, structs = positions or load_positions()
    src = _strip_comments(text)
    problems = []

    for name, idxs in calls.items():
        # Cheap gate: most of the ~66 char-id call names never appear in a
        # given generated file, and a substring test is far cheaper than a
        # regex scan of the whole blob.
        if name not in src:
            continue
        for m in re.finditer(r'\b%s\s*\(' % re.escape(name), src):
            open_idx = m.end() - 1
            close = _match_paren(src, open_idx)
            if close < 0:
                continue
            args = _split_top_level(src[open_idx + 1:close])
            for i in sorted(idxs):
                if i < len(args) and _BARE_INT.match(args[i]):
                    problems.append(
                        "%s:%d: %s() arg %d is the bare literal %s "
                        "(want CHARID(%s))"
                        % (label, _line_of(text, m.start()), name, i,
                           args[i], args[i].strip('() ')))

    for tname, idxs in structs.items():
        if tname not in src:
            continue
        for m in re.finditer(r'\b%s\b[^=;{]*=\s*' % re.escape(tname), src):
            brace = src.find('{', m.end() - 1)
            if brace < 0:
                continue
            close = _match_brace(src, brace)
            if close < 0:
                continue
            body = src[brace + 1:close]
            # An array-of-struct initialiser's top-level elements are the rows;
            # a single-struct initialiser IS one row. Both are handled by
            # treating a brace-wrapped element as a row and the whole body as
            # the row when nothing is brace-wrapped.
            elements = [e for e in _split_top_level(body) if e]
            rows = [e for e in elements if e.startswith('{')]
            if not rows:
                rows = ['{' + body + '}']
            for row_text in rows:
                inner = row_text[1:row_text.rindex('}')] if row_text.endswith('}') \
                    else row_text[1:]
                row = _split_top_level(inner)
                for i in sorted(idxs):
                    if i < len(row) and _BARE_INT.match(row[i]):
                        problems.append(
                            "%s:%d: %s initialiser field %d is the bare "
                            "literal %s (want CHARID(%s))"
                            % (label, _line_of(text, brace),
                               tname, i, row[i], row[i].strip('() ')))

    return (not problems), problems


def check_file(path, positions=None):
    text = Path(path).read_text(encoding='latin-1')
    return check_text(text, label=str(path), positions=positions)


EMITTER = "SWFRecomp/src/swf.cpp"
# The helper every char-id emission must go through (see the CHARACTER ID
# WRAPPER comment in tag.h).
EMIT_HELPER = "charId("

_STRING_LITERAL = re.compile(r'"(?:\\.|[^"\\])*"')


def check_emitter(path=None):
    """Source-side check: does the recompiler wrap at every emission site?

    The generated-C check can only see what the SWFs it was pointed at happen
    to emit — an emission site no sampled SWF reaches is invisible to it. This
    reads the emitter instead: it pulls every function name the recompiler
    writes into generated C out of the C++ string literals, intersects that
    with the char-id call names the headers declare, and reports any such name
    whose emission statement does not mention `charId(`.

    A "statement" is the run of source lines from the line naming the call to
    the line ending it (`;`), which is how the ostream chains in swf.cpp are
    laid out. Returns (ok, [problem strings]).
    """
    src_path = PROJECT_ROOT / (path or EMITTER)
    raw = src_path.read_text(encoding='utf-8', errors='replace')
    src = _strip_comments(raw)
    lines = raw.split('\n')
    calls, _structs = load_positions()

    # Function names the recompiler WRITES (they appear inside a C++ string
    # literal, followed by "("). \t / \n escapes are turned into spaces
    # first, or the tab in "\ttagDefineSound(" glues onto the name.
    emitted = set()
    for m in _STRING_LITERAL.finditer(src):
        s = m.group(0).replace('\\t', ' ').replace('\\n', ' ')
        emitted |= set(re.findall(r'\b([A-Za-z_]\w*)\s*\(', s))

    problems = []
    for name in sorted(emitted & set(calls)):
        sites = 0
        for i, line in enumerate(lines):
            if ('"' not in line) or (name not in line):
                continue
            # Only the line that OPENS the emission (the literal naming the
            # call); the arguments follow on this or later lines.
            if not re.search(r'"[^"]*\b%s\s*\(' % re.escape(name),
                             line.replace('\\t', ' ').replace('\\n', ' ')):
                continue
            sites += 1
            stmt = []
            for j in range(i, min(i + 40, len(lines))):
                stmt.append(lines[j])
                if lines[j].rstrip().endswith(';'):
                    break
            if EMIT_HELPER not in '\n'.join(stmt):
                problems.append(
                    "%s:%d: emits %s() but the statement never calls %s — "
                    "a character id is going out as a bare literal"
                    % (src_path.name, i + 1, name, EMIT_HELPER))
        if sites == 0:
            problems.append(
                "%s: %s() looks emitted but no emission statement was found "
                "(the scanner needs updating)" % (src_path.name, name))
    return (not problems), problems


GENERATED_GLOBS = ("RecompiledTags/*.c", "*.c")


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__.split('\n')[0])
    ap.add_argument('files', nargs='*', help='generated .c files to check')
    ap.add_argument('--tree', action='append', default=[],
                    help='directory to scan (RecompiledTags/*.c, then *.c)')
    ap.add_argument('--list-positions', action='store_true',
                    help='print the char-id positions derived from the headers')
    ap.add_argument('--emitter', action='store_true',
                    help='check %s instead of generated C: every emitted '
                         'char-id call must go through charId()' % EMITTER)
    args = ap.parse_args(argv)

    positions = load_positions()
    if args.list_positions:
        calls, structs = positions
        print('char-id call arguments (from %s):' % ', '.join(HEADERS))
        for name in sorted(calls):
            print('  %-42s arg %s' % (name, sorted(calls[name])))
        print('char-id struct fields:')
        for name in sorted(structs):
            print('  %-42s field %s' % (name, sorted(structs[name])))
        return 0

    if args.emitter:
        ok, problems = check_emitter()
        if not ok:
            print('CHARID oracle (emitter): %d problem(s)' % len(problems),
                  file=sys.stderr)
            for p in problems:
                print('  ' + p, file=sys.stderr)
            return 1
        print('CHARID oracle (emitter): clean — every char-id call %s emits '
              'goes through %s' % (EMITTER, EMIT_HELPER))
        return 0

    targets = [Path(f) for f in args.files]
    for d in args.tree:
        d = Path(d)
        for pat in GENERATED_GLOBS:
            targets.extend(sorted(d.glob(pat)))
    targets = [t for t in dict.fromkeys(targets) if t.is_file()]
    if not targets:
        ap.error('no files to check (pass files or --tree)')

    problems = []
    for t in targets:
        _ok, probs = check_file(t, positions=positions)
        problems.extend(probs)

    if problems:
        print('CHARID oracle: %d offender(s) in %d file(s)'
              % (len(problems), len(targets)), file=sys.stderr)
        for p in problems:
            print('  ' + p, file=sys.stderr)
        return 1
    print('CHARID oracle: clean over %d file(s)' % len(targets))
    return 0


if __name__ == '__main__':
    sys.exit(main())
