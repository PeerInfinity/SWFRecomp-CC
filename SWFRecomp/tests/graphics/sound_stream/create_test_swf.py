#!/usr/bin/env python3
"""Generate test.swf for sound stream graphics test.

Uses SoundStreamHead (tag 18) + SoundStreamBlock (tag 19) with uncompressed
16-bit PCM audio streamed across multiple frames. A blue square is displayed
for visual identification.
"""
import math
import struct
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import SWFMLBuilder, SolidFill, ShapeSetup, LineTo

# 12 fps, 24 frames = 2 seconds of audio
fps = 12
num_frames = 24
sample_rate = 44100
frequency = 440.0
samples_per_frame = sample_rate // fps  # 3675 samples per frame

swf = SWFMLBuilder(width=550, height=400, fps=fps, version=5)
swf.set_background(255, 255, 255)

# SoundStreamHead (tag 18): set up stream format
# Playback: 44100Hz, 16-bit, mono
# Stream: 44100Hz, 16-bit, mono, uncompressed LE (format 3)
swf.sound_stream_head(
    stream_format=3,  # uncompressed LE
    stream_rate=3,    # 44100 Hz
    stream_size=1,    # 16-bit
    stream_stereo=False,
    playback_rate=3,
    playback_size=1,
    playback_stereo=False,
    avg_sample_count=samples_per_frame,
)

# Blue square for visual identification — 100x100 px = 2000x2000 twips
shape = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000))
shape.add_fill(SolidFill(40, 80, 200))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# Place shape at (200, 100)px = (4000, 2000) twips
swf.place_object(object_id=1, depth=1, trans_x=4000, trans_y=2000)

# Generate and stream audio across frames
for frame in range(num_frames):
    # Generate PCM for this frame
    pcm_data = bytearray()
    for i in range(samples_per_frame):
        t = (frame * samples_per_frame + i) / sample_rate
        sample = int(32767 * math.sin(2 * math.pi * frequency * t))
        pcm_data.extend(struct.pack('<h', sample))

    swf.sound_stream_block(pcm_samples=bytes(pcm_data))
    swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
