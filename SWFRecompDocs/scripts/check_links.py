#!/usr/bin/env python3
"""Check the relative Markdown links (and #anchors) in the given files.

Usage: python3 SWFRecompDocs/scripts/check_links.py README.md SWFRecompDocs/README.md ...
Prints one OK/BAD line per relative link and a summary; exits 1 if any is broken.
External (scheme:) links are skipped. Anchors use GitHub's heading slugs.
"""
import re, sys, os
from pathlib import Path
LINK = re.compile(r'\[[^\]]*\]\(([^)\s]+)\)')
def slug(h):
    h = h.strip().lower()
    h = re.sub(r'[^\w\- ]', '', h)   # GitHub: drop punctuation (keeps _ and -)
    return h.replace(' ', '-')
def anchors(p):
    out=set(); inside=False
    for line in Path(p).read_text().splitlines():
        if line.startswith('```'): inside = not inside; continue
        m = re.match(r'#+\s+(.*)', line)
        if m and not inside: out.add(slug(m.group(1)))
    return out
bad=0; total=0; ext=0
for f in sys.argv[1:]:
    f=Path(f); text=f.read_text()
    text=re.sub(r'```.*?```', '', text, flags=re.S)
    for target in LINK.findall(text):
        if re.match(r'[a-z]+:', target): ext+=1; continue
        total+=1
        path, _, frag = target.partition('#')
        dest = (f.parent / path).resolve() if path else f.resolve()
        ok = dest.exists()
        if ok and frag:
            ok = dest.is_file() and frag in anchors(dest)
        if not ok: bad+=1
        print(f"{'OK ' if ok else 'BAD'} {f}: {target}")
print(f"--- {total} relative links checked, {bad} broken; {ext} external links skipped")
sys.exit(1 if bad else 0)
