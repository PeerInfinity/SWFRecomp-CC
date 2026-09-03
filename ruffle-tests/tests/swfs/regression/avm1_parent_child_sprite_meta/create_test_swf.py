#!/usr/bin/env python3
"""Build child.swf and test.swf for regression/avm1_parent_child_sprite_meta.

WHAT THIS PINS DOWN
-------------------
A loaded child SWF's character ids are shifted by `movie_id * 1000` so they
cannot collide with the parent's dictionary. That shift used to be applied by
`generate_child_movie_file` (`ruffle-tests/verify_output.py`) with ONE `re.sub`
PER EMITTED CALL NAME, so any char-id-carrying emission the hand-maintained
list did not name kept its RAW id and silently disagreed with every emission
that was offset.

The sprite-metadata quartet was the provably half-applied case: the sprite
itself (`tagDefineSprite`) and every `tagPlaceObject2*` were offset, while

    tagSetSpriteLabels(char_id, ...)        -> label -> frame lookup
    tagSetSpritePlacements(sprite_id, ...)  -> loop-back survives_rewind
    tagSetSpriteFrameCounts(char_id, ...)   -> body-vs-header frame counts
    tagSetSpriteNoEndTag(char_id)           -> "malformed sprite doesn't loop"

were not. All four key on the dictionary/store entry that `tagDefineSprite`
created under the OFFSET id, so in a loaded child all four were dropped on the
floor (`dictionary[raw].type != CHAR_TYPE_SPRITE` -> early return; the label
and placement stores simply never match a lookup).

The fix wraps every char id at the point the RECOMPILER emits it (`CHARID(x)`,
`SWFModernRuntime/include/libswf/tag.h`) so the harness does one
value-keyed substitution instead of maintaining a list of call names. That also
reaches char ids that are NOT call arguments — `FramePlacement`'s `char_id`
struct field, which no call-name-keyed scheme can see.

THE SHAPE
---------
    parent test.swf  (AVM1, SWF8, MTASC + spliced tags)  sprites 21/22/23
                     loadMovie("child.swf") into _root.holder
    child.swf        (AVM1, SWF8, hand-built)            sprites 1/2/3

Both movies carry the SAME THREE hand-built sprites at DIFFERENT char ids, so
the parent row is a control (it must keep working) and the child row is the
discriminator. The ids deliberately do not collide: a collision would make the
child's raw-id metadata writes land on the parent's live dictionary entries,
which is a second, noisier failure mode this test is not trying to measure.

    sprite A (id 1 / 21)  header frameCount 2, body: place "inner" @1, SF,
                          FrameLabel "two", SF, End
        -> tagSetSpriteLabels   : gotoAndStop("two") must reach frame 2
        -> tagSetSpritePlacements: "inner" is an MC that frame 0 re-places at
           the same depth, so it must SURVIVE every loop-back with its
           identity (no onUnload). With no placement table registered under
           the id the runtime looks up, ng_loopback_entry_survives degrades to
           "no static survivors" and onUnload fires on every wrap.
    sprite B (id 2 / 22)  header frameCount 1, body: SF, place "inner2" @1,
                          SF, and NO End record
        -> tagSetSpriteFrameCounts: header underdeclares (1) vs body (2
           ShowFrames), so without the correction sprite_frame_count stays 1
           and the runtime skips it as a 1-frame sprite -> it never advances
           to frame 2 and "inner2" never appears.
        -> tagSetSpriteNoEndTag  : an unterminated body must park on its last
           frame instead of looping, which is what keeps "inner2" visible
           once frame 2 has run.
    sprite C (id 3 / 23)  the empty 1-frame sprite used as "inner"/"inner2".

Expected rows, and what each state produces:

    row     master (raw ids)   fixed        reads
    pU:     n                  n            parent inner ever onUnload'd
    cU:     y                  n            child  inner ever onUnload'd
    pA:     2                  2            parent gotoAndStop("two")
    cA:     1                  2            child  gotoAndStop("two")
    pB:     y                  y            parent sprite B reached frame 2
    cB:     n                  y            child  sprite B reached frame 2

The `armed` line proves the child's sprite A instantiated and its `inner` was
reachable from AS before the measurement window opened; without it a silent
"child never loaded" would look like a clean sweep on the unload rows.

The parent's sprites are SPLICED into MTASC's output (before its first
ShowFrame, so they land in frame 1 alongside the class DoAction) because MTASC
has no timeline-authoring syntax.
"""
import struct
import subprocess
import sys
from pathlib import Path

HERE = Path(__file__).resolve().parent

# char ids: (inner, spriteA, spriteB)
CHILD_IDS = (3, 1, 2)
PARENT_IDS = (23, 21, 22)

CHILD_NAMES = ("inner", "csp", "inner2", "cfc")
PARENT_NAMES = ("inner", "psp", "inner2", "pfc")

PARENT_DEPTHS = (10, 11)   # main-timeline depths for parent sprite A / B
CHILD_DEPTHS = (1, 2)      # main-timeline depths for child sprite A / B


def tag(code, data):
    if len(data) < 0x3F:
        return struct.pack('<H', (code << 6) | len(data)) + data
    return struct.pack('<HI', (code << 6) | 0x3F, len(data)) + data


def place_object2(depth, char_id, name):
    """PlaceObject2 with HasCharacter | HasMatrix | HasName.

    The identity MATRIX is written out (nbits=0 scale/rotate/translate -> a
    single zero byte) rather than omitted: a no-matrix place is the "Modify"
    shape and takes a different runtime path.
    """
    flags = 0x02 | 0x04 | 0x20
    body = (struct.pack('<BHH', flags, depth, char_id)
            + b'\x00'                                    # identity MATRIX
            + name.encode('ascii') + b'\x00')
    return tag(26, body)


def show_frame():
    return tag(1, b'')


def frame_label(label):
    return tag(43, label.encode('ascii') + b'\x00')


def end_tag():
    return struct.pack('<H', 0)


def define_sprite(char_id, declared_frames, body):
    return tag(39, struct.pack('<HH', char_id, declared_frames) + body)


def sprites(ids, names):
    """The three sprites, in definition order (inner first)."""
    inner_id, a_id, b_id = ids
    inner_name, _a_name, inner2_name, _b_name = names

    out = b''
    # C: empty 1-frame sprite, used as the nested child of both A and B.
    out += define_sprite(inner_id, 1, show_frame() + end_tag())
    # A: well-formed 2-frame looper with a label on frame 2 and a named
    #    nested MC that frame 1 re-places (so it must survive the wrap).
    out += define_sprite(a_id, 2,
                         place_object2(1, inner_id, inner_name)
                         + show_frame()
                         + frame_label("two")
                         + show_frame()
                         + end_tag())
    # B: header underdeclares (1) vs two ShowFrames, and the body is NOT
    #    terminated by an End record.
    out += define_sprite(b_id, 1,
                         show_frame()
                         + place_object2(1, inner_id, inner2_name)
                         + show_frame())
    return out


def build_child(path):
    inner_id, a_id, b_id = CHILD_IDS
    _in, a_name, _in2, b_name = CHILD_NAMES
    tags = sprites(CHILD_IDS, CHILD_NAMES)
    tags += place_object2(CHILD_DEPTHS[0], a_id, a_name)
    tags += place_object2(CHILD_DEPTHS[1], b_id, b_name)
    tags += show_frame()
    tags += end_tag()

    # RECT nbits=15, 0..4000 twips square (200x200 px stage, never rendered).
    rect = bytes([0x78, 0x00, 0x0F, 0xA0, 0x00, 0x00, 0x0F, 0xA0, 0x00])
    body = rect + struct.pack('<H', 30 << 8) + struct.pack('<H', 1) + tags
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', 8, file_length) + body)
    print(f'Created {path} (SWF8, sprites {CHILD_IDS}, {file_length} bytes)')


def read_swf(path):
    """Split an SWF into (version, header_prefix, tag_stream)."""
    raw = path.read_bytes()
    sig, version = raw[:3], raw[3]
    body = raw[8:]
    if sig == b'CWS':
        import zlib
        body = zlib.decompress(body)
    elif sig != b'FWS':
        raise SystemExit(f'{path}: unsupported signature {sig!r}')
    nbits = body[0] >> 3
    rect_len = (5 + 4 * nbits + 7) // 8
    prefix = body[:rect_len + 4]        # RECT + frame rate + frame count
    return version, prefix, body[rect_len + 4:]


def first_showframe_offset(tag_bytes):
    """Byte offset of the first ShowFrame (code 1) record."""
    pos = 0
    while pos + 2 <= len(tag_bytes):
        code_len = struct.unpack('<H', tag_bytes[pos:pos + 2])[0]
        code, length = code_len >> 6, code_len & 0x3F
        hdr = 2
        if length == 0x3F:
            length = struct.unpack('<I', tag_bytes[pos + 2:pos + 6])[0]
            hdr = 6
        if code == 1:
            return pos
        if code == 0:
            break
        pos += hdr + length
    raise SystemExit('no ShowFrame tag found')


def used_char_ids(tag_bytes):
    ids = set()
    define_tags = {2, 4, 6, 7, 10, 11, 13, 14, 17, 19, 20, 21, 22, 32, 33, 35,
                   36, 37, 39, 46, 48, 60, 75, 78, 83, 84, 90}
    pos = 0
    while pos + 2 <= len(tag_bytes):
        code_len = struct.unpack('<H', tag_bytes[pos:pos + 2])[0]
        code, length = code_len >> 6, code_len & 0x3F
        hdr = 2
        if length == 0x3F:
            length = struct.unpack('<I', tag_bytes[pos + 2:pos + 6])[0]
            hdr = 6
        if code == 0:
            break
        if code in define_tags and length >= 2:
            ids.add(struct.unpack('<H', tag_bytes[pos + hdr:pos + hdr + 2])[0])
        pos += hdr + length
    return ids


def build_parent(path):
    mtasc = Path.home() / 'CC' / 'mtasc' / 'bin' / 'mtasc'
    std = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std'
    std8 = Path.home() / 'CC' / 'mtasc' / 'ocaml' / 'mtasc' / 'std8'
    cmd = [str(mtasc), '-cp', str(std), '-cp', str(std8), '-main',
           '-header', '200:200:30', 'Parent.as', '-swf', path.name,
           '-version', '8']
    print('$ ' + ' '.join(cmd))
    subprocess.run(cmd, cwd=str(HERE), check=True)

    version, prefix, tag_bytes = read_swf(path)
    taken = used_char_ids(tag_bytes)
    clash = taken & set(PARENT_IDS)
    if clash:
        raise SystemExit(f'MTASC output already uses char ids {sorted(clash)}')

    _in, a_name, _in2, b_name = PARENT_NAMES
    extra = (sprites(PARENT_IDS, PARENT_NAMES)
             + place_object2(PARENT_DEPTHS[0], PARENT_IDS[1], a_name)
             + place_object2(PARENT_DEPTHS[1], PARENT_IDS[2], b_name))

    cut = first_showframe_offset(tag_bytes)
    body = prefix + tag_bytes[:cut] + extra + tag_bytes[cut:]
    file_length = 8 + len(body)
    path.write_bytes(b'FWS' + struct.pack('<BI', version, file_length) + body)
    print(f'Created {path} ({path.stat().st_size} bytes, sprites '
          f'{PARENT_IDS} spliced into frame 1)')


if __name__ == '__main__':
    build_child(HERE / 'child.swf')
    try:
        build_parent(HERE / 'test.swf')
    except FileNotFoundError:
        print('MTASC not found; test.swf left as-is', file=sys.stderr)
