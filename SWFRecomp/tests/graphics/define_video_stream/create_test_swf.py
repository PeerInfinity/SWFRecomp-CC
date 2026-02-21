#!/usr/bin/env python3
"""Generate test.swf for define_video_stream graphics test.

Tests DefineVideoStream (tag 60) and VideoFrame (tag 61): defines a video
stream character and includes a video frame tag. The video is not placed on
the display list (no runtime video decoding). A visible red square is placed
to verify the SWF renders correctly despite the presence of video tags.

Frame 1: Red square (100x100 px) at center
"""
import sys, os, struct
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, SolidFill,
    ShapeSetup, LineTo,
)

# Stage: 550x400 pixels
swf = SWFMLBuilder(width=550, height=400, fps=12, version=7)
swf.set_background(255, 255, 255)

# Define a red square (100x100 px = 2000x2000 twips), object ID 1
red = swf.define_shape(object_id=1, bounds=(0, 2000, 0, 2000))
red.add_fill(SolidFill(255, 0, 0))
red.add_edges([
    ShapeSetup(x=0, y=0, fillStyle1=1),
    LineTo(2000, 0),
    LineTo(0, 2000),
    LineTo(-2000, 0),
    LineTo(0, -2000),
])

# DefineVideoStream (tag 60)
# Format: UI16 CharacterID, UI16 NumFrames, UI16 Width, UI16 Height,
#          UB[4] VideoFlagsDeblocking, UB[1] VideoFlagsSmoothing, UI8 CodecID
# Using character ID 2, 1 frame, 160x120 pixels, no deblocking, no smoothing,
# codec 2 (Sorenson H.263)
video_char_id = 2
num_frames = 1
video_width = 160
video_height = 120
# Flags byte: UB[4] deblocking=0, UB[1] smoothing=0, UB[3] reserved=0
# Actually the spec packs it as: UB[4] + UB[1] then UI8 codec
# Upper 4 bits = deblocking (0), bit 3 = smoothing (0), lower 3 bits = reserved
video_flags = 0x00  # deblocking=0, smoothing=0
codec_id = 2  # Sorenson H.263
video_stream_body = struct.pack('<HHHHBB', video_char_id, num_frames,
                                video_width, video_height,
                                video_flags, codec_id)
swf.add_raw_tag(60, video_stream_body)

# VideoFrame (tag 61)
# Format: UI16 StreamID, UI16 FrameNum, then codec-specific data
# We include a minimal dummy payload (not a valid H.263 frame, but the
# recompiler just skips the data)
stream_id = video_char_id
frame_num = 0
dummy_video_data = bytes([0x00] * 16)  # 16 bytes of dummy codec data
video_frame_body = struct.pack('<HH', stream_id, frame_num) + dummy_video_data
swf.add_raw_tag(61, video_frame_body)

# Place the red square at center: (225, 150) px = (4500, 3000) twips
swf.place_object(object_id=1, depth=1, trans_x=4500, trans_y=3000)

# Frame 1: red square visible, video tags parsed but not displayed
swf.show_frame()

swf.save("test.swf")
