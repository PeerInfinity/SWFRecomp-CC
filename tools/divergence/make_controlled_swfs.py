#!/usr/bin/env python3
"""Build the two minimal controlled SWFs called for by Phase 0 of
SWFRecompDocs/plans/defer-newly-placed-sprite-advance-plan.md.

Both SWFs are intended to be run through the divergence harness with the
tracer injected, so we get F<n>-prefixed observations on each tick.

  sprite_first_tick_load.swf
    Root:    Frame 1 places a 1-frame sprite at depth 1, then ShowFrame.
             Frame 2 has nothing but ShowFrame.
    Sprite:  Frame 1 does trace("SP-load"). 1 frame total.

  sprite_first_tick_advance.swf
    Root:    Frame 1 calls stop(), places a 2-frame sprite at depth 1, then
             ShowFrame. (One frame total — the sprite is the thing whose
             advance we're probing.)
    Sprite:  Frame 1 trace("SP-f1"). Frame 2 trace("SP-f2"). 2 frames total.

These pin down (a) on which tick the sprite's Load (frame 1) script first
fires and (b) on which tick its frame-2 script first fires.
"""
import struct
import os
from pathlib import Path

HERE = Path(__file__).resolve().parent

# --- AVM1 bytecode helpers (copied from demos/ruffle-inject/make_test_swfs.py) ---

def make_tag(tag_type, body):
    length = len(body)
    if length < 63:
        header = struct.pack('<H', (tag_type << 6) | length)
    else:
        header = struct.pack('<H', (tag_type << 6) | 0x3F) + struct.pack('<I', length)
    return header + body


def make_do_action(bytecode):
    return make_tag(12, bytecode)


def push_string_trace(msg):
    """AVM1: Push(string) + Trace. Caller is responsible for the End opcode."""
    msg_bytes = msg.encode('ascii') + b'\x00'
    push = b'\x96' + struct.pack('<H', 1 + len(msg_bytes)) + b'\x00' + msg_bytes
    return push + b'\x26'  # Trace


def stop_op():
    """AVM1 Stop opcode (0x07)."""
    return b'\x07'


def end_op():
    return b'\x00'


def make_rect(width_twips, height_twips):
    max_val = max(width_twips, height_twips)
    nbits = max_val.bit_length() + 1
    bits = []
    for bit in range(4, -1, -1):
        bits.append((nbits >> bit) & 1)
    for val in [0, width_twips, 0, height_twips]:
        for bit in range(nbits - 1, -1, -1):
            bits.append((val >> bit) & 1)
    while len(bits) % 8 != 0:
        bits.append(0)
    out = bytearray()
    for i in range(0, len(bits), 8):
        b = 0
        for j in range(8):
            b = (b << 1) | bits[i + j]
        out.append(b)
    return bytes(out)


def make_swf(tags, width=200, height=200, fps=12, version=8, frame_count=1):
    rect = make_rect(width * 20, height * 20)
    frame_rate = struct.pack('<BB', 0, fps)
    frame_count_b = struct.pack('<H', frame_count)
    body = rect + frame_rate + frame_count_b + b''.join(tags)
    header = b'FWS' + struct.pack('<B', version) + struct.pack('<I', 8 + len(body))
    return header + body


def make_place_object2(depth, char_id, has_name=None):
    """Minimal PlaceObject2 with HasCharacter set (and optionally HasName).
    No matrix/cxform — we don't care about pixels for these tests.
    """
    flags = 0x02  # PlaceFlagHasCharacter
    body = bytearray()
    if has_name is not None:
        flags |= 0x20  # PlaceFlagHasName
    body.append(flags)
    body += struct.pack('<H', depth)
    body += struct.pack('<H', char_id)
    if has_name is not None:
        body += has_name.encode('ascii') + b'\x00'
    return make_tag(26, bytes(body))


def make_define_sprite(char_id, frame_count, frame_tags):
    """DefineSprite (tag 39). frame_tags must include ShowFrame + End."""
    body = struct.pack('<HH', char_id, frame_count) + b''.join(frame_tags)
    return make_tag(39, body)


# --- SWF 1: sprite_first_tick_load.swf ---

sprite1_frame_tags = [
    make_do_action(push_string_trace("SP-load") + end_op()),
    make_tag(1, b''),   # ShowFrame
    make_tag(0, b''),   # End (terminates the sprite tag stream)
]
sprite1 = make_define_sprite(char_id=1, frame_count=1, frame_tags=sprite1_frame_tags)

swf1_tags = [
    make_tag(9, b'\xff\xff\xff'),       # SetBackgroundColor white
    sprite1,                            # define sprite 1
    make_place_object2(depth=1, char_id=1, has_name="sprite1"),
    make_tag(1, b''),                   # ShowFrame (ends root frame 1)
    make_tag(1, b''),                   # ShowFrame (ends root frame 2)
    make_tag(0, b''),                   # End
]
swf1 = make_swf(swf1_tags, frame_count=2)

out1 = HERE / "sprite_first_tick_load.swf"
out1.write_bytes(swf1)
print(f"sprite_first_tick_load.swf: {len(swf1)} bytes -> {out1}")

# --- SWF 2: sprite_first_tick_advance.swf ---

sprite2_frame_tags = [
    make_do_action(push_string_trace("SP-f1") + end_op()),
    make_tag(1, b''),  # ShowFrame (ends sprite frame 1)
    make_do_action(push_string_trace("SP-f2") + end_op()),
    make_tag(1, b''),  # ShowFrame (ends sprite frame 2)
    make_tag(0, b''),  # End
]
sprite2 = make_define_sprite(char_id=1, frame_count=2, frame_tags=sprite2_frame_tags)

# Root has one frame. The stop() makes sure the root doesn't advance — so we
# can isolate sprite advance behavior. We put stop BEFORE PlaceObject2 so
# that even if stop ran "after" the placement in some interpretation, both
# tags are visible by the time the root frame's tag stream is fully processed.
root_stop = make_do_action(push_string_trace("ROOT-f1") + stop_op() + end_op())

swf2_tags = [
    make_tag(9, b'\xff\xff\xff'),       # SetBackgroundColor white
    sprite2,                            # define sprite 1 (2 frames)
    root_stop,                          # ROOT-f1 trace + stop()
    make_place_object2(depth=1, char_id=1, has_name="sprite1"),
    make_tag(1, b''),                   # ShowFrame
    make_tag(0, b''),                   # End
]
swf2 = make_swf(swf2_tags, frame_count=1)

out2 = HERE / "sprite_first_tick_advance.swf"
out2.write_bytes(swf2)
print(f"sprite_first_tick_advance.swf: {len(swf2)} bytes -> {out2}")

# --- SWF 3: sprite_calls_root_play.swf ---
# Matches Pong's preloader pattern: root has multiple frames, frame 1 stops and
# places a sprite, sprite frame 2 calls _root.play(). Used to see when the
# sprite's frame 2 script fires.
#
#   Root:    Frame 1: stop(), place sprite_1, ShowFrame
#            Frame 2: trace("ROOT-f2"), ShowFrame
#   Sprite:  Frame 1: trace("SP-f1")
#            Frame 2: trace("SP-f2-before-play"), _root.play(), trace("SP-f2-after-play")

# AVM1 bytecode for "_root.play()":
#   Push "_root"        (string)
#   GetVariable         (0x1C)
#   Push 0              (int — arg count)
#   Push "play"         (string)
#   CallMethod          (0x52)
#   Pop                 (0x17, discard return value)
def call_root_play():
    out = bytearray()
    # Push "_root"
    s = b'_root\x00'
    out += b'\x96' + struct.pack('<H', 1 + len(s)) + b'\x00' + s
    # GetVariable
    out += b'\x1c'
    # Push int 0
    out += b'\x96\x05\x00\x07\x00\x00\x00\x00'
    # Push "play"
    s = b'play\x00'
    out += b'\x96' + struct.pack('<H', 1 + len(s)) + b'\x00' + s
    # CallMethod
    out += b'\x52'
    # Pop (discard return)
    out += b'\x17'
    return bytes(out)


sprite3_frame_tags = [
    make_do_action(push_string_trace("SP-f1") + end_op()),
    make_tag(1, b''),  # ShowFrame
    make_do_action(
        push_string_trace("SP-f2-before-play")
        + call_root_play()
        + push_string_trace("SP-f2-after-play")
        + end_op()
    ),
    make_tag(1, b''),  # ShowFrame
    make_tag(0, b''),  # End
]
sprite3 = make_define_sprite(char_id=1, frame_count=2, frame_tags=sprite3_frame_tags)

swf3_tags = [
    make_tag(9, b'\xff\xff\xff'),
    sprite3,
    make_do_action(push_string_trace("ROOT-f1") + stop_op() + end_op()),
    make_place_object2(depth=1, char_id=1, has_name="sprite1"),
    make_tag(1, b''),                       # ShowFrame (root frame 1)
    make_do_action(push_string_trace("ROOT-f2") + end_op()),
    make_tag(1, b''),                       # ShowFrame (root frame 2)
    make_do_action(push_string_trace("ROOT-f3") + stop_op() + end_op()),
    make_tag(1, b''),                       # ShowFrame (root frame 3)
    make_tag(0, b''),                       # End
]
swf3 = make_swf(swf3_tags, frame_count=3)

out3 = HERE / "sprite_calls_root_play.swf"
out3.write_bytes(swf3)
print(f"sprite_calls_root_play.swf: {len(swf3)} bytes -> {out3}")
