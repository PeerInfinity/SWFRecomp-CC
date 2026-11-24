#pragma once

#include <cstddef>

namespace SWFRecomp
{

// Flash-faithful JPEG decode (IJG v7+ ISLOW + DCT-scaled chroma + Flash's
// truncating YCbCr->RGB; see src/jpeg_flash.cpp). Returns malloc'd RGB
// (3 bytes/pixel), or nullptr for streams it does not handle (progressive,
// arithmetic, 12-bit, CMYK, damaged entropy data).
unsigned char* decodeJpegFlash(const unsigned char* data, size_t len, int* w, int* h);

// decodeJpegFlash with an stb_image fallback (stbi_load_from_memory, 3
// channels). Release the result with stbi_image_free (malloc/free).
// SWFRECOMP_JPEG_DECODER=stb forces the stb path (A/B switch).
unsigned char* decodeJpegRgb(const unsigned char* data, size_t len, int* w, int* h,
                             const char* what);

}
