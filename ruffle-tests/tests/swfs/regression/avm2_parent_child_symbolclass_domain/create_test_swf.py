#!/usr/bin/env python3
"""Regenerate test.swf + child.swf for avm2_parent_child_symbolclass_domain.

Pins down: a character placed by a LOADED child movie gets its SymbolClass
class resolved in the ApplicationDomain of the movie instance that placed it
(Ruffle movie_clip.rs preload_symbol_class:
`library_for_movie(self.movie()).avm2_domain()`), not in the root domain. The
child loads into a fresh domain (default LoaderContext), so its classes exist
nowhere else and a root-domain lookup finds nothing: the character came up a
bare MovieClip and its class constructor never ran. Two rows:

  timeline:  the child ROOT's frame 1 places Outer, whose frame places Inner
  script:    `new Outer()` from the parent, via the child domain's getDefinition
             — a script-created symbol instance, whose timeline still places
             Inner and must resolve it in the class's own movie's domain

Fixed in avm2_display.c (Avm2DisplayObjectExt.movie_scope) — see
SWFRecompDocs/status/avm2-child-symbolclass-binding.md.

mxmlc cannot author a DefineSprite symbol that places another symbol, so the
child is compiled normally (it links Inner/Outer into its ABC) and then this
script injects, into frame 1:
  DefineSprite 1  (Inner: one empty frame)
  DefineSprite 2  (Outer: places character 1 at depth 1)
  SymbolClass     1 -> Inner, 2 -> Outer   (appended to mxmlc's own row 0 -> Child)
  PlaceObject2    character 2 at depth 1 on the child root

Requires the Apache Flex SDK (mxmlc). Run from this directory:
    python3 create_test_swf.py
"""
import pathlib
import struct
import subprocess
import zlib

HERE = pathlib.Path(__file__).resolve().parent
MXMLC = pathlib.Path.home() / "CC/flex-sdk/bin/mxmlc"
COMMON = ["-omit-trace-statements=false", "-target-player=11.1",
          "-static-link-runtime-shared-libraries=true",
          "-default-size", "200", "150", "-default-frame-rate", "30"]

T_END, T_SHOWFRAME, T_PLACEOBJECT2, T_DEFINESPRITE = 0, 1, 26, 39
T_DOABC, T_SYMBOLCLASS = 82, 76


def tag(code, body):
    if len(body) < 0x3F:
        return struct.pack("<H", (code << 6) | len(body)) + body
    return struct.pack("<HI", (code << 6) | 0x3F, len(body)) + body


def place(char_id, depth):
    # PlaceObject2: HasMatrix | HasCharacter; identity matrix is the single
    # byte 0 (no scale, no rotate, 0 translate bits). Deliberately UNNAMED: a
    # named instance on these sealed classes would add a #1056 field-set error
    # that has nothing to do with the class binding.
    return tag(T_PLACEOBJECT2,
               bytes([0x04 | 0x02]) + struct.pack("<HH", depth, char_id) + b"\x00")


def sprite(sprite_id, frame_tags):
    return tag(T_DEFINESPRITE,
               struct.pack("<HH", sprite_id, 1) + frame_tags
               + tag(T_SHOWFRAME, b"") + tag(T_END, b""))


def read_tags(data, pos):
    tags = []
    while pos < len(data):
        (hdr,) = struct.unpack_from("<H", data, pos)
        code, length, start = hdr >> 6, hdr & 0x3F, pos + 2
        if length == 0x3F:
            (length,) = struct.unpack_from("<I", data, start)
            start += 4
        tags.append((code, data[start:start + length]))
        pos = start + length
        if code == T_END:
            break
    return tags


def inject(path):
    raw = path.read_bytes()
    sig, version = raw[:3], raw[3]
    body = zlib.decompress(raw[8:]) if sig == b"CWS" else raw[8:]
    assert sig in (b"CWS", b"FWS"), sig
    nbits = body[0] >> 3
    header_len = (5 + 4 * nbits + 7) // 8 + 4   # RECT + frame rate + count
    header, tags = body[:header_len], read_tags(body, header_len)

    out, done_defs, done_sc, done_place = b"", False, False, False
    for code, tb in tags:
        if code == T_DOABC and not done_defs:
            out += sprite(1, b"") + sprite(2, place(1, 1))
            done_defs = True
        if code == T_SYMBOLCLASS and not done_sc:
            (n,) = struct.unpack_from("<H", tb, 0)
            rows = tb[2:] + struct.pack("<H", 1) + b"Inner\x00" \
                          + struct.pack("<H", 2) + b"Outer\x00"
            out += tag(T_SYMBOLCLASS, struct.pack("<H", n + 2) + rows)
            done_sc = True
            continue
        if code == T_SHOWFRAME and not done_place:
            out += place(2, 1)
            done_place = True
        out += tag(code, tb)
    assert done_defs and done_sc and done_place, (done_defs, done_sc, done_place)

    body = header + out
    swf = b"FWS" + bytes([version]) + struct.pack("<I", 8 + len(body)) + body
    path.write_bytes(swf)


def main():
    child = HERE / "child.swf"
    subprocess.run([str(MXMLC), *COMMON, "-source-path", str(HERE),
                    "-output", str(child), str(HERE / "Child.as")], check=True)
    inject(child)
    subprocess.run([str(MXMLC), *COMMON, "-output", str(HERE / "test.swf"),
                    str(HERE / "Test.as")], check=True)
    print("wrote", child, "and", HERE / "test.swf")


if __name__ == "__main__":
    main()
