#!/usr/bin/env python3
"""Per-game accepted-divergence facility for the divergence harness.

Mirrors the AVM1 suite's ACCEPTED_DIFFS.md + ignored_tests.txt: a small,
explicit, per-game manifest lists NARROW, documented artifact patterns that the
harness should treat as accepted (a known observer/tooling artifact, not a real
runtime divergence). Without a manifest the harness behaves exactly as before.

Each rule absorbs a diverging (ruffle, swfrecomp) trace-line PAIR ONLY when ALL
of the following hold:
  - some whitespace-token of the lines matches the rule's path regex, AND
  - the two lines are identical in their non-field prefix (frame + path) and in
    EVERY key=value field EXCEPT exactly the one named field, AND
  - that field's value is `ruffle_value` on the Ruffle side and
    `swfrecomp_value` on the SWFRecomp side (compared as exact strings).

That triple constraint makes a rule incapable of masking a real bug: any line
where another field also differs, or where the named field's values are not the
exact documented pair, or whose path doesn't match, falls through and is flagged
normally. A rule is therefore pinned to one specific, documented artifact shape
(e.g. Pacman #10b: `Pac`/`CPac` `_cf` reads the goto-SOURCE frame 5 where Ruffle
reads the post-goto frame 1, and NOTHING else about the line differs).

Manifest location: tools/divergence/accepted/<swf_stem>.txt
Manifest format (one rule per line; a line whose first non-space char is `#` is
a comment — note `#` is NOT stripped mid-line, so tags like `#10b` survive):
  <path_regex> | <field> | <ruffle_value> | <swfrecomp_value> | <tag>
"""
import re
from pathlib import Path

HERE = Path(__file__).resolve().parent
DEFAULT_ACCEPTED_DIR = HERE / "accepted"


def _parse_line(line: str):
    """Split a trace line into (prefix_tokens, fields).

    Prefix tokens are whitespace-separated tokens with no `=` (the frame token
    and the clip path); fields is a dict of the `key=value` tokens (first `=`
    splits)."""
    prefix = []
    fields = {}
    for tok in line.split():
        if "=" in tok:
            k, _, v = tok.partition("=")
            fields[k] = v
        else:
            prefix.append(tok)
    return prefix, fields


class AcceptRule:
    """One documented accepted-diff pattern. See module docstring for semantics."""

    def __init__(self, path_regex: str, field: str,
                 ruffle_value: str, swfrecomp_value: str, tag: str):
        self.path_regex = path_regex
        self.path_re = re.compile(path_regex)
        self.field = field
        self.ruffle_value = ruffle_value
        self.swfrecomp_value = swfrecomp_value
        self.tag = tag

    def matches(self, ruffle_line: str, swfrecomp_line: str) -> bool:
        rp, rf = _parse_line(ruffle_line)
        sp, sf = _parse_line(swfrecomp_line)
        # Non-field prefix (frame + path) must be byte-identical on both sides.
        if rp != sp:
            return False
        # The rule's path regex must match one of those prefix tokens.
        if not any(self.path_re.search(t) for t in rp):
            return False
        # Same set of field keys, and the named field must be present.
        if rf.keys() != sf.keys() or self.field not in rf:
            return False
        # EXACTLY the named field may differ between the two sides.
        differing = [k for k in rf if rf[k] != sf[k]]
        if differing != [self.field]:
            return False
        # ...and its two values must be the exact documented pair.
        return (rf[self.field] == self.ruffle_value and
                sf[self.field] == self.swfrecomp_value)

    def __repr__(self):
        return (f"AcceptRule({self.path_regex!r}, {self.field!r}, "
                f"{self.ruffle_value!r}, {self.swfrecomp_value!r}, {self.tag!r})")


def load_manifest(stem: str, accepted_dir: Path = DEFAULT_ACCEPTED_DIR):
    """Load the accept rules for a game by SWF stem. Returns [] when no manifest
    file exists (so behavior is unchanged for any game without one)."""
    path = Path(accepted_dir) / f"{stem}.txt"
    if not path.exists():
        return []
    rules = []
    for raw in path.read_text().splitlines():
        s = raw.strip()
        if not s or s.startswith("#"):
            continue
        parts = [p.strip() for p in s.split("|")]
        if len(parts) != 5:
            raise ValueError(
                f"{path}: rule needs 5 '|'-separated fields "
                f"(path_regex | field | ruffle_value | swfrecomp_value | tag), "
                f"got {len(parts)}: {raw!r}")
        rules.append(AcceptRule(*parts))
    return rules


def manifest_path(stem: str, accepted_dir: Path = DEFAULT_ACCEPTED_DIR) -> Path:
    return Path(accepted_dir) / f"{stem}.txt"


def match_any(rules, ruffle_line: str, swfrecomp_line: str):
    """Return the tag of the first rule that accepts this diverging pair, else
    None."""
    for r in rules:
        if r.matches(ruffle_line, swfrecomp_line):
            return r.tag
    return None
