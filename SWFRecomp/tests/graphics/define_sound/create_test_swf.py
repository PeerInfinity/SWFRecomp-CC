#!/usr/bin/env python3
"""Generate test.swf for define_sound graphics test.

A DefineSound (tag 14) with uncompressed 16-bit PCM 440Hz sine wave,
played via StartSound (tag 15) on frame 0. A green square is displayed
for visual identification.
"""
import math
import struct
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import SWFMLBuilder, SolidFill, ShapeSetup, LineTo

swf = SWFMLBuilder(width=550, height=400, fps=12, version=5)
swf.set_background(255, 255, 255)

# Generate 0.5s of 440Hz sine wave, 16-bit mono, 44100 Hz
sample_rate = 44100
duration = 0.5
frequency = 440.0
num_samples = int(sample_rate * duration)
pcm_data = bytearray()
for i in range(num_samples):
    t = i / sample_rate
    sample = int(32767 * math.sin(2 * math.pi * frequency * t))
    pcm_data.extend(struct.pack('<h', sample))

# DefineSound (tag 14) — sound_id=1, uncompressed LE, 44100Hz, 16-bit, mono
swf.define_sound(sound_id=1, sample_rate=44100, sample_size=16,
                 stereo=False, pcm_samples=bytes(pcm_data))

# Green square for visual identification — 100x100 px = 2000x2000 twips
shape = swf.define_shape(object_id=2, bounds=(0, 2000, 0, 2000))
shape.add_fill(SolidFill(0, 180, 0))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Place shape at center-ish (200, 100) px = (4000, 2000) twips
swf.place_object(object_id=2, depth=1, trans_x=4000, trans_y=2000)

# StartSound (tag 15) — play sound_id=1
swf.start_sound(sound_id=1)

swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
