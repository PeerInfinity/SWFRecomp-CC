#!/usr/bin/env python3
"""Generate test.swf for SoundStreamHead2 (tag 45) graphics test.

Same as sound_stream test but uses SoundStreamHead2 (tag 45) instead of
SoundStreamHead (tag 18). A red square is displayed for visual identification.
"""
import math
import struct
import sys
import os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import SWFMLBuilder, SolidFill, ShapeSetup, LineTo

fps = 12
num_frames = 12  # 1 second
sample_rate = 44100
frequency = 880.0  # A5
samples_per_frame = sample_rate // fps

swf = SWFMLBuilder(width=550, height=400, fps=fps, version=5)
swf.set_background(255, 255, 255)

# SoundStreamHead2 (tag 45): uncompressed LE, 44100Hz, 16-bit, mono
swf.sound_stream_head2(
    stream_format=3, stream_rate=3, stream_size=1, stream_stereo=False,
    playback_rate=3, playback_size=1, playback_stereo=False,
    avg_sample_count=samples_per_frame,
)

# Red square for visual identification
shape = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000))
shape.add_fill(SolidFill(200, 40, 40))
shape.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])
swf.place_object(object_id=1, depth=1, trans_x=4000, trans_y=2000)

for frame in range(num_frames):
    pcm_data = bytearray()
    for i in range(samples_per_frame):
        t = (frame * samples_per_frame + i) / sample_rate
        sample = int(32767 * math.sin(2 * math.pi * frequency * t))
        pcm_data.extend(struct.pack('<h', sample))
    swf.sound_stream_block(pcm_samples=bytes(pcm_data))
    swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
