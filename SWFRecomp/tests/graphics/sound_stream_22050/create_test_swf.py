#!/usr/bin/env python3
"""Generate test.swf for sound stream at 22050 Hz (exercises audio_mix
resampling). Variant of graphics/sound_stream — same 440 Hz tone for
2 seconds, but the stream rate is 22050 Hz so audio_mix must resample
to the hardware 44100 Hz output. Without resampling, the tone plays
1 second at 880 Hz (2× speed + 2× pitch). A green square is the
visual marker.
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
sample_rate = 22050
frequency = 440.0
samples_per_frame = sample_rate // fps  # 1837 samples per frame

swf = SWFMLBuilder(width=550, height=400, fps=fps, version=5)
swf.set_background(255, 255, 255)

# SoundStreamHead (tag 18): 22050 Hz, 16-bit, mono, uncompressed LE
swf.sound_stream_head(
    stream_format=3,  # uncompressed LE
    stream_rate=2,    # 22050 Hz
    stream_size=1,    # 16-bit
    stream_stereo=False,
    playback_rate=2,
    playback_size=1,
    playback_stereo=False,
    avg_sample_count=samples_per_frame,
)

# Green square for visual identification — 100x100 px = 2000x2000 twips
shape = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000))
shape.add_fill(SolidFill(40, 200, 80))
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
    pcm_data = bytearray()
    for i in range(samples_per_frame):
        t = (frame * samples_per_frame + i) / sample_rate
        sample = int(32767 * math.sin(2 * math.pi * frequency * t))
        pcm_data.extend(struct.pack('<h', sample))

    swf.sound_stream_block(pcm_samples=bytes(pcm_data))
    swf.show_frame()

output_path = os.path.join(os.path.dirname(__file__), "test.swf")
swf.save(output_path)
