# SWF analysis tools

Small Python parsers that pretty-print specific SWF tag types — used
during runtime-bug diagnosis to compare what the SWF actually contains
against what the recompiler / runtime emits.

## Inventory

| Tool | Usage |
|---|---|
| `parse_define_text.py <path/to/test.swf>` | Dumps all DefineText / DefineText2 tags with per-record flags (HasFont, HasColor, HasYOffset, HasXOffset), font ID, color, x/y offsets, height, glyph count, and the (glyph_index, advance) pairs for each glyph. Used to diagnose the GAMEOVER mid-word wrap bug (`2026-05-27-snake-countdown-gameover.md`). |
| `parse_swf_text.py <path/to/test.swf> <char_id>` | Lower-level: dumps the raw DefineText record stream for a specific character ID. Shows glyph_bits / advance_bits / first-record flag byte breakdown. Useful when `parse_define_text.py`'s structured output isn't enough. |
| `parse_swf_flags.py <path/to/test.swf> <char_id>` | Just the flag-byte breakdown for a specific DefineText's first record. Used to confirm the bit positions (HasYOffset = bit 1, HasXOffset = bit 0) when investigating the `swf.cpp` field-order bug. |

## When useful

These were all written during specific bug investigations and aren't
needed for routine development. Keep them around because:

- Whenever the recompiler's `tagDefineText` emits something that
  doesn't match the SWF spec, comparing the SWF binary's raw
  structure to the recompiled C output is the fastest way to localize
  the bug.
- Diagnostic patterns generalize — extending one of these for a new
  tag type (DefineShape, PlaceObject2 details, etc.) is usually a
  small modification.

## Pattern

Each parser starts with the same boilerplate:

```python
def read_swf(path):
    with open(path, 'rb') as f:
        data = f.read()
    if data[:3] == b'CWS':  # compressed
        return data[:8] + zlib.decompress(data[8:])
    return data
```

Then walks the tag stream (`tag_header = (code << 6) | length`, etc.).
If you need to parse a new tag type, copy the boilerplate and add
the tag-specific logic.
