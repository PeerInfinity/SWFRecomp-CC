#!/usr/bin/env python3
"""Generate test.swf for mess graphics test.

Bitmap-filled shape using JPEG image data with ClippedBitmap fill style.
"""
import sys, os
sys.path.insert(0, os.path.join(os.path.dirname(__file__), ".."))

from swfmill_helpers import (
    SWFMLBuilder, ClippedBitmapFill,
    ShapeSetup, LineTo,
)

# JPEG tables (SWF JPEGTables tag, encoded as base64)
JPEG_TABLES = (
    "/9j/2wBDABALDA4MChAODQ4SERATGCgaGBYWGDEjJR0oOjM9PDkzODdASFxO"
    "QERXRTc4UG1RV19iZ2hnPk1xeXBkeFxlZ2P/2wBDARESEhgVGC8aGi9jQjhC"
    "Y2NjY2NjY2NjY2NjY2NjY2NjY2NjY2NjY2NjY2NjY2NjY2NjY2NjY2NjY2Nj"
    "Y2NjY2P/xAAfAAABBQEBAQEBAQAAAAAAAAAAAQIDBAUGBwgJCgv/xAC1EAAC"
    "AQMDAgQDBQUEBAAAAX0BAgMABBEFEiExQQYTUWEHInEUMoGRoQgjQrHBFVLR"
    "8CQzYnKCCQoWFxgZGiUmJygpKjQ1Njc4OTpDREVGR0hJSlNUVVZXWFlaY2Rl"
    "ZmdoaWpzdHV2d3h5eoOEhYaHiImKkpOUlZaXmJmaoqOkpaanqKmqsrO0tba3"
    "uLm6wsPExcbHyMnK0tPU1dbX2Nna4eLj5OXm5+jp6vHy8/T19vf4+fr/xAAf"
    "AQADAQEBAQEBAQEBAAAAAAAAAQIDBAUGBwgJCgv/xAC1EQACAQIEBAMEBwUE"
    "BAABAncAAQIDEQQFITEGEkFRB2FxEyIygQgUQpGhscEJIzNS8BVictEKFiQ0"
    "4SXxFxgZGiYnKCkqNTY3ODk6Q0RFRkdISUpTVFVWV1hZWmNkZWZnaGlqc3R1"
    "dnd4eXqCg4SFhoeIiYqSk5SVlpeYmZqio6Slpqeoqaqys7S1tre4ubrCw8TF"
    "xsfIycrS09TV1tfY2dri4+Tl5ufo6ery8/T19vf4+fr/2Q=="
)

# JPEG image data (SWF DefineBits tag, encoded as base64)
JPEG_DATA = (
    "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"
    "2HlS1Ovs44RGAjA1b2qB0Fc1ZeaIY/IDNI3P4Vp/abiDAuI/+BLWLRzl4ome"
    "lFVBexsMhxz70UCONPWkoPWlVc969cwFUEnirouGEYUqM461HHHtXjmr1lZr"
    "csd7hAPfk1lU5WryKXkU1DyPhQST2rStdKkfBlOB6CtOCyigHyIM+verca4r"
    "llXe0S0gs7KKIABRWgAAMAVAnFShq5xj6xte1JYIzbxN+9brjsKtapqK2NsX"
    "GC54UZrjppXnlaVzlmOTXRQp8zuxNjTknnrWv4atxJfGRsHyxwD61jk1PZ3c"
    "1nMJIjg9x612VE3FpEo7snFMfa4wwqlp2qRX8R6JIOq5q21eY04uzLMi+0xp"
    "pCUHFUTpM4kAC8V0eaVZMU+Zi5TKt9KY4ycVqW9qkCDgZ9ak31FLLtUliFUd"
    "SaV2wsPkmC8CuK1Ji2o3BP8AfNbV5rKRkrbr5jf3j0FYM7tNM8rj5nOTiuqj"
    "TktWDaIaKdgU7y66LCuInWrNQBSO1Sq+etcGLoTl70dT1sBiacFySdh1Iy7h"
    "ilorzE2nc9lpSVmVWGDTcZOBU8ydxUI4YZOMV6UJqUbng16bpyaZ0MFwtraI"
    "gABA5qnPetI2F5JqO2tbi+I2ghPWt2z0mG2ALDc3vUnCYYs7hxu8s80V1YKj"
    "gAUUtAPNz1oGc0HrT4F3SivVMi+i7VA64FODbTkHBpBxTSVBpWGX01aeNAvy"
    "NjuwpRrl0OiRf98n/GswkdqTOan2UOwXZrf29d/3Yv8Avk/40HX7v+7F+R/x"
    "rIz70hOKXJT7Bdli6upLqQySnJ9OwquDzRupuafPGOgWHmkLU3JorGVdIpQY"
    "5JGjcMjEEdxXT6VrUdwqQ3B2y9M9jXLUAkHI61z1KnN0LULHflfSmlQoLMcA"
    "ckmub0/xBLbRNHcBpv7pzyKrXurXV+ShOyM/wL0rNa6ILG5d61bwZSEea/se"
    "BWLdajPcn943HoOlVV2quBTWYV6FKjyK73M2+w7PpQH9ajzSbq3JJsqaTOOh"
    "qPdSZoAmEnrS7lNQBqcGFAEwYetOBzUFKGIrlrYWFXXZnbh8bUo6PVEx5FVp"
    "VweKlEnrSS7SuSRXmSp1KD1PWdWliYXW6K4vrm0IaCUrjtW1ZeKUdAt4m1/7"
    "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"
    "KKAP/9k="
)

swf = SWFMLBuilder(width=550, height=400, fps=12, version=4)
swf.set_background(255, 255, 255)
swf.add_jpeg_tables(JPEG_TABLES)
swf.define_bits_jpeg(object_id=1, jpeg_data_base64=JPEG_DATA)

shape = swf.define_shape(object_id=2, bounds=(3070, 7930, 1579, 6439))
shape.add_fill(ClippedBitmapFill(
    object_id=65535,
    matrix={"scaleX": 20.0, "scaleY": 20.0, "transX": 0, "transY": 0},
))
shape.add_fill(ClippedBitmapFill(
    object_id=1,
    matrix={"scaleX": 20.0, "scaleY": 20.0, "transX": 3070, "transY": 1579},
))

shape.add_edges([
    ShapeSetup(x=7930, y=6439, fillStyle1=2),
    LineTo(-4860, 0),
    LineTo(0, -4860),
    LineTo(4860, 0),
    LineTo(0, 4860),
])

swf.place_object(object_id=2, depth=1)
swf.show_frame()
swf.save("test.swf")
