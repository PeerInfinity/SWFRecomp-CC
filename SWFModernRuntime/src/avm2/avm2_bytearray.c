// flash.utils.ByteArray — port of Ruffle core/src/avm2/bytearray.rs
// (ByteArrayStorage), globals/flash/utils/byte_array.rs (natives), and
// ByteArray.as, plus the Endian / CompressionAlgorithm constant classes.
//
// Storage is a plain grow-on-write byte buffer with a read/write cursor.
// Reads past the end throw EOFError 2030; writes that would exceed u32
// range throw RangeError 2006. Strings read out of the buffer are
// UTF-8-validated with Rust's from_utf8_lossy "maximal subparts" rule so
// byte dumps match Ruffle exactly. readUTF/readUTFBytes strip a UTF-8 BOM
// and truncate at the first NUL (an FP bug we replicate); toString strips
// a UTF-8 BOM or decodes the whole buffer as UTF-16 on an FF FE / FE FF
// BOM, and does NOT truncate at NULs.
//
// compress/uncompress use the already-linked zlib ("zlib" = zlib wrapper,
// "deflate" = raw stream, level 9 = Ruffle's Compression::best); "lzma"
// is not compiled in (compress yields an empty buffer, uncompress throws
// 2058, matching Ruffle-without-lzma). readMultiByte/writeMultiByte
// handle utf-8 and utf-16le/be natively and delegate other charsets
// (shift-jis) to iconv; unknown labels fall back to UTF-8 exactly like
// encoding_rs's for_label().unwrap_or(UTF_8).

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <zlib.h>
#ifndef __EMSCRIPTEN__
#include <errno.h>
#include <iconv.h>
#endif

#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <memory/heap.h>

#include <avm2/avm2_gc.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_ops.h>

Avm2ByteArrayExt* avm2_bytearray_ext_of(Avm2Value v)
{
	if (v.kind != AVM2_VALUE_OBJECT || v.u.obj == NULL) return NULL;
	Avm2Context* ctx = avm2_get_context();
	if (ctx->builtins.bytearray_class == NULL) return NULL;
	for (Avm2Class* c = v.u.obj->cls; c != NULL; c = c->super_class)
	{
		if (c == ctx->builtins.bytearray_class)
		{
			return (Avm2ByteArrayExt*) v.u.obj->native_ext;
		}
	}
	return NULL;
}

// GC (Stage 11): free the backing byte buffer a swept ByteArray owns
// (avm2_alloc'd). No-op for non-ByteArrays / empty buffers.
void avm2_bytearray_gc_free_ext(Avm2Context* ctx, Avm2Object* o)
{
	Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(avm2_object_value(o));
	if (ba == NULL || ba->bytes == NULL) return;
	heap_free(ctx->app, ba->bytes);
	ba->bytes = NULL;
}

static _Noreturn void throw_eof(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.eof_error_class,
	                 "Error #2030: End of file was encountered.");
}

static _Noreturn void throw_2006(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.range_error_class,
	                 "Error #2006: The supplied index is out of bounds.");
}

static _Noreturn void throw_2007(Avm2Context* ctx, const char* param)
{
	avm2_throw_error(ctx, ctx->builtins.type_error_class,
	                 "Error #2007: Parameter %s must be non-null.", param);
}

static _Noreturn void throw_2008(Avm2Context* ctx, const char* param)
{
	avm2_throw_error(ctx, ctx->builtins.argument_error_class,
	                 "Error #2008: Parameter %s must be one of the accepted "
	                 "values.", param);
}

static _Noreturn void throw_2058(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.io_error_class,
	                 "Error #2058: There was an error decompressing the data.");
}

// ---------------------------------------------------------------------------
// Storage
// ---------------------------------------------------------------------------

void avm2_bytearray_set_length_public(Avm2Context* ctx, Avm2ByteArrayExt* ba,
                                      uint32_t new_len);

static void ba_set_length(Avm2Context* ctx, Avm2ByteArrayExt* ba, uint32_t new_len)
{
	if (new_len > ba->cap)
	{
		uint32_t new_cap = ba->cap == 0 ? 32 : ba->cap;
		while (new_cap < new_len) new_cap *= 2;
		uint8_t* grown = avm2_alloc(ctx, new_cap);
		if (ba->len > 0) memcpy(grown, ba->bytes, ba->len);
		ba->bytes = grown;
		ba->cap = new_cap;
	}
	if (new_len > ba->len)
	{
		memset(ba->bytes + ba->len, 0, new_len - ba->len);
	}
	ba->len = new_len;
	if (ba->position > new_len) ba->position = new_len;
}

// Write at an arbitrary offset, growing (Ruffle write_at).
static void ba_write_at(Avm2Context* ctx, Avm2ByteArrayExt* ba, const uint8_t* buf,
                        uint32_t n, uint32_t offset)
{
	if ((uint64_t) offset + n > 0xFFFFFFFFull)
	{
		throw_2006(ctx);
	}
	uint32_t new_len = offset + n;
	if (ba->len < new_len) ba_set_length(ctx, ba, new_len);
	if (n > 0) memmove(ba->bytes + offset, buf, n);
}

static void ba_write_bytes(Avm2Context* ctx, Avm2ByteArrayExt* ba,
                           const uint8_t* buf, uint32_t n)
{
	ba_write_at(ctx, ba, buf, n, ba->position);
	ba->position += n;
}

// Read at an arbitrary offset (Ruffle read_at): EOF if out of range.
static const uint8_t* ba_read_at(Avm2Context* ctx, const Avm2ByteArrayExt* ba,
                                 uint32_t n, uint32_t offset)
{
	if ((uint64_t) offset + n > ba->len)
	{
		throw_eof(ctx);
	}
	return ba->bytes + offset;
}

static const uint8_t* ba_read_bytes(Avm2Context* ctx, Avm2ByteArrayExt* ba, uint32_t n)
{
	const uint8_t* p = ba_read_at(ctx, ba, n, ba->position);
	ba->position += n;
	return p;
}

static uint32_t ba_bytes_available(const Avm2ByteArrayExt* ba)
{
	return (ba->position <= ba->len) ? ba->len - ba->position : 0;
}

// Endian-aware scalar I/O.
static void ba_write_scalar(Avm2Context* ctx, Avm2ByteArrayExt* ba,
                            const uint8_t* be_bytes, uint32_t n)
{
	uint8_t buf[8];
	for (uint32_t i = 0; i < n; i++)
	{
		buf[i] = ba->endian_little ? be_bytes[n - 1 - i] : be_bytes[i];
	}
	ba_write_bytes(ctx, ba, buf, n);
}

static void ba_read_scalar(Avm2Context* ctx, Avm2ByteArrayExt* ba,
                           uint8_t* out_be, uint32_t n)
{
	const uint8_t* p = ba_read_bytes(ctx, ba, n);
	for (uint32_t i = 0; i < n; i++)
	{
		out_be[i] = ba->endian_little ? p[n - 1 - i] : p[i];
	}
}

static void ba_write_u16(Avm2Context* ctx, Avm2ByteArrayExt* ba, uint16_t v)
{
	uint8_t be[2] = { (uint8_t) (v >> 8), (uint8_t) v };
	ba_write_scalar(ctx, ba, be, 2);
}

static void ba_write_u32(Avm2Context* ctx, Avm2ByteArrayExt* ba, uint32_t v)
{
	uint8_t be[4] = { (uint8_t) (v >> 24), (uint8_t) (v >> 16),
	                  (uint8_t) (v >> 8), (uint8_t) v };
	ba_write_scalar(ctx, ba, be, 4);
}

static uint16_t ba_read_u16(Avm2Context* ctx, Avm2ByteArrayExt* ba)
{
	uint8_t be[2];
	ba_read_scalar(ctx, ba, be, 2);
	return (uint16_t) ((be[0] << 8) | be[1]);
}

static uint32_t ba_read_u32(Avm2Context* ctx, Avm2ByteArrayExt* ba)
{
	uint8_t be[4];
	ba_read_scalar(ctx, ba, be, 4);
	return ((uint32_t) be[0] << 24) | ((uint32_t) be[1] << 16)
	       | ((uint32_t) be[2] << 8) | be[3];
}

void avm2_bytearray_set_length_public(Avm2Context* ctx, Avm2ByteArrayExt* ba,
                                      uint32_t new_len)
{
	ba_set_length(ctx, ba, new_len);
}

// ---------------------------------------------------------------------------
// UTF-8 lossy validation (Rust String::from_utf8_lossy, maximal subparts)
// ---------------------------------------------------------------------------

static const char UTF8_REPLACEMENT[3] = { (char) 0xEF, (char) 0xBF, (char) 0xBD };

// Returns the length in bytes of the valid UTF-8 sequence at p (1-4), or 0
// if invalid; *consumed = bytes of the maximal valid subpart to skip.
static uint32_t utf8_seq_len(const uint8_t* p, uint32_t avail, uint32_t* consumed)
{
	uint8_t b0 = p[0];
	uint32_t need;
	uint8_t lo = 0x80, hi = 0xBF;
	if (b0 < 0x80) { *consumed = 1; return 1; }
	else if (b0 >= 0xC2 && b0 <= 0xDF) need = 1;
	else if (b0 == 0xE0) { need = 2; lo = 0xA0; }
	else if (b0 >= 0xE1 && b0 <= 0xEC) need = 2;
	else if (b0 == 0xED) { need = 2; hi = 0x9F; }
	else if (b0 >= 0xEE && b0 <= 0xEF) need = 2;
	else if (b0 == 0xF0) { need = 3; lo = 0x90; }
	else if (b0 >= 0xF1 && b0 <= 0xF3) need = 3;
	else if (b0 == 0xF4) { need = 3; hi = 0x8F; }
	else { *consumed = 1; return 0; }

	for (uint32_t i = 1; i <= need; i++)
	{
		if (i >= avail) { *consumed = i; return 0; }
		uint8_t b = p[i];
		// The special lo/hi range applies to the FIRST continuation only.
		uint8_t l = (i == 1) ? lo : 0x80;
		uint8_t h = (i == 1) ? hi : 0xBF;
		if (b < l || b > h) { *consumed = i; return 0; }
	}
	*consumed = need + 1;
	return need + 1;
}

static const Avm2String* utf8_lossy(Avm2Context* ctx, const uint8_t* bytes, uint32_t n)
{
	// Worst case: every byte invalid -> 3x expansion.
	char* buf = avm2_alloc(ctx, n * 3 + 1);
	uint32_t out = 0;
	uint32_t i = 0;
	while (i < n)
	{
		uint32_t consumed;
		uint32_t len = utf8_seq_len(bytes + i, n - i, &consumed);
		if (len > 0)
		{
			memcpy(buf + out, bytes + i, len);
			out += len;
			i += len;
		}
		else
		{
			memcpy(buf + out, UTF8_REPLACEMENT, 3);
			out += 3;
			i += consumed;
		}
	}
	buf[out] = '\0';
	return avm2_string_new(ctx, buf, out);
}

// avmplus's lenient UTF-8 decoder (Ruffle wstr DecodeAvmUtf8, used by
// AvmString::new_utf8_bytes): a lone continuation/invalid byte decodes to
// its own byte VALUE (0x89 -> U+0089), multibyte sequences take at most 3
// continuation bytes and fall back to the lead byte's value when malformed
// or overlong. readUTF/readUTFBytes/toString use this — NOT strict lossy.
static uint32_t avm_utf8_next(const uint8_t* p, uint32_t avail, uint32_t* consumed)
{
	uint8_t first = p[0];
	uint32_t ones = 0;
	while (ones < 8 && (first & (0x80u >> ones))) ones++;
	*consumed = 1;
	if (ones <= 1) return first;
	uint32_t mb = ones - 1;
	if (mb > 3) mb = 3;
	if (avail - 1 < mb) return first;
	uint32_t ch = (ones >= 8) ? 0 : (uint32_t) (first & (0xFFu >> ones));
	for (uint32_t i = 1; i <= mb; i++)
	{
		uint8_t b = p[i];
		if ((b & 0xC0) != 0x80) return first;
		ch = (ch << 6) | (b & 0x3F);
	}
	if (ch < 0x80) return first;
	*consumed = 1 + mb;
	return ch;
}

static uint32_t utf8_encode(uint32_t cp, char* out);

static const Avm2String* avm_utf8_lenient(Avm2Context* ctx, const uint8_t* bytes,
                                          uint32_t n)
{
	char* buf = avm2_alloc(ctx, n * 4 + 1);
	uint32_t out = 0;
	uint32_t i = 0;
	while (i < n)
	{
		uint32_t consumed;
		uint32_t cp = avm_utf8_next(bytes + i, n - i, &consumed);
		i += consumed;
		out += utf8_encode(cp, buf + out);
	}
	buf[out] = '\0';
	return avm2_string_new(ctx, buf, out);
}

// Encode one code point as UTF-8.
static uint32_t utf8_encode(uint32_t cp, char* out)
{
	if (cp < 0x80) { out[0] = (char) cp; return 1; }
	if (cp < 0x800)
	{
		out[0] = (char) (0xC0 | (cp >> 6));
		out[1] = (char) (0x80 | (cp & 0x3F));
		return 2;
	}
	if (cp < 0x10000)
	{
		out[0] = (char) (0xE0 | (cp >> 12));
		out[1] = (char) (0x80 | ((cp >> 6) & 0x3F));
		out[2] = (char) (0x80 | (cp & 0x3F));
		return 3;
	}
	out[0] = (char) (0xF0 | (cp >> 18));
	out[1] = (char) (0x80 | ((cp >> 12) & 0x3F));
	out[2] = (char) (0x80 | ((cp >> 6) & 0x3F));
	out[3] = (char) (0x80 | (cp & 0x3F));
	return 4;
}

// Decode UTF-16 bytes (chunks of 2; a trailing odd byte is dropped) into a
// UTF-8 string. Unpaired surrogates become U+FFFD.
static const Avm2String* utf16_to_utf8(Avm2Context* ctx, const uint8_t* bytes,
                                       uint32_t n, int little)
{
	uint32_t units = n / 2;
	char* buf = avm2_alloc(ctx, units * 3 + 4);
	uint32_t out = 0;
	for (uint32_t i = 0; i < units; i++)
	{
		uint16_t u = little
			? (uint16_t) (bytes[i * 2] | (bytes[i * 2 + 1] << 8))
			: (uint16_t) ((bytes[i * 2] << 8) | bytes[i * 2 + 1]);
		uint32_t cp = u;
		if (u >= 0xD800 && u <= 0xDBFF && i + 1 < units)
		{
			uint16_t u2 = little
				? (uint16_t) (bytes[(i + 1) * 2] | (bytes[(i + 1) * 2 + 1] << 8))
				: (uint16_t) ((bytes[(i + 1) * 2] << 8) | bytes[(i + 1) * 2 + 1]);
			if (u2 >= 0xDC00 && u2 <= 0xDFFF)
			{
				cp = 0x10000 + (((uint32_t) (u - 0xD800)) << 10) + (u2 - 0xDC00);
				i++;
			}
			else
			{
				cp = 0xFFFD;
			}
		}
		else if (u >= 0xD800 && u <= 0xDFFF)
		{
			cp = 0xFFFD;
		}
		out += utf8_encode(cp, buf + out);
	}
	buf[out] = '\0';
	return avm2_string_new(ctx, buf, out);
}

// readUTF/readUTFBytes semantics (Ruffle read_utf_bytes): strip a UTF-8
// BOM, truncate at the first NUL.
static const Avm2String* utf_bytes_to_string(Avm2Context* ctx, const uint8_t* bytes,
                                             uint32_t n)
{
	if (n >= 3 && bytes[0] == 0xEF && bytes[1] == 0xBB && bytes[2] == 0xBF)
	{
		bytes += 3;
		n -= 3;
	}
	for (uint32_t i = 0; i < n; i++)
	{
		if (bytes[i] == '\0')
		{
			n = i;
			break;
		}
	}
	return avm_utf8_lenient(ctx, bytes, n);
}

// ---------------------------------------------------------------------------
// Charset conversion (readMultiByte / writeMultiByte)
// ---------------------------------------------------------------------------

enum { CS_UTF8, CS_UTF16LE, CS_UTF16BE, CS_ICONV };

// Map a WHATWG-ish charset label; unknown labels fall back to UTF-8
// (encoding_rs for_label().unwrap_or(UTF_8)). Returns the class and, for
// CS_ICONV, the iconv encoding name.
static int charset_classify(const Avm2String* label, const char** iconv_name)
{
	char low[64];
	uint32_t n = label->len < 63 ? label->len : 63;
	for (uint32_t i = 0; i < n; i++)
	{
		char c = label->utf8[i];
		low[i] = (c >= 'A' && c <= 'Z') ? (char) (c + 32) : c;
	}
	low[n] = '\0';
	if (strcmp(low, "utf-16le") == 0 || strcmp(low, "utf-16") == 0
	    || strcmp(low, "unicode") == 0)
	{
		return CS_UTF16LE;
	}
	if (strcmp(low, "utf-16be") == 0) return CS_UTF16BE;
	if (strcmp(low, "shift-jis") == 0 || strcmp(low, "shift_jis") == 0
	    || strcmp(low, "sjis") == 0 || strcmp(low, "s-jis") == 0
	    || strcmp(low, "s_jis") == 0 || strcmp(low, "ms_kanji") == 0
	    || strcmp(low, "csshiftjis") == 0 || strcmp(low, "windows-31j") == 0
	    || strcmp(low, "x-sjis") == 0)
	{
		*iconv_name = "SHIFT_JIS";
		return CS_ICONV;
	}
	if (strcmp(low, "euc-jp") == 0) { *iconv_name = "EUC-JP"; return CS_ICONV; }
	if (strcmp(low, "big5") == 0) { *iconv_name = "BIG5"; return CS_ICONV; }
	if (strcmp(low, "gbk") == 0 || strcmp(low, "gb2312") == 0)
	{
		*iconv_name = "GBK";
		return CS_ICONV;
	}
	if (strcmp(low, "euc-kr") == 0) { *iconv_name = "EUC-KR"; return CS_ICONV; }
	if (strncmp(low, "iso-8859-", 9) == 0 || strncmp(low, "windows-12", 10) == 0)
	{
		// iconv understands these names directly (upper-case them back).
		static char name[64];
		for (uint32_t i = 0; i <= n; i++)
		{
			char c = low[i];
			name[i] = (c >= 'a' && c <= 'z') ? (char) (c - 32) : c;
		}
		*iconv_name = name;
		return CS_ICONV;
	}
	return CS_UTF8;  // incl. "utf-8", "", unknown labels
}

#ifndef __EMSCRIPTEN__
// iconv decode `from` -> UTF-8 with U+FFFD on invalid sequences.
static const Avm2String* iconv_decode(Avm2Context* ctx, const char* enc,
                                      const uint8_t* bytes, uint32_t n)
{
	iconv_t cd = iconv_open("UTF-8", enc);
	if (cd == (iconv_t) -1) return utf8_lossy(ctx, bytes, n);
	uint32_t cap = n * 4 + 8;
	char* buf = avm2_alloc(ctx, cap);
	char* in = (char*) bytes;
	size_t in_left = n;
	char* out = buf;
	size_t out_left = cap - 1;
	while (in_left > 0)
	{
		size_t rc = iconv(cd, &in, &in_left, &out, &out_left);
		if (rc != (size_t) -1) break;
		if (errno == EILSEQ || errno == EINVAL)
		{
			if (out_left < 3) break;
			memcpy(out, UTF8_REPLACEMENT, 3);
			out += 3;
			out_left -= 3;
			if (errno == EINVAL) break;  // truncated trailing sequence
			in++;
			in_left--;
		}
		else
		{
			break;
		}
	}
	iconv_close(cd);
	*out = '\0';
	return avm2_string_new(ctx, buf, (uint32_t) (out - buf));
}

// iconv encode UTF-8 -> `to`; undecodable chars are dropped.
static uint32_t iconv_encode(Avm2Context* ctx, const char* enc, const Avm2String* s,
                             uint8_t** out_bytes)
{
	iconv_t cd = iconv_open(enc, "UTF-8");
	if (cd == (iconv_t) -1)
	{
		*out_bytes = (uint8_t*) s->utf8;
		return s->len;
	}
	uint32_t cap = s->len * 4 + 8;
	char* buf = avm2_alloc(ctx, cap);
	char* in = (char*) s->utf8;
	size_t in_left = s->len;
	char* out = buf;
	size_t out_left = cap;
	while (in_left > 0)
	{
		size_t rc = iconv(cd, &in, &in_left, &out, &out_left);
		if (rc != (size_t) -1) break;
		if (errno == EILSEQ || errno == EINVAL)
		{
			in++;
			in_left--;
		}
		else
		{
			break;
		}
	}
	iconv_close(cd);
	*out_bytes = (uint8_t*) buf;
	return (uint32_t) (out - buf);
}
#endif

// UTF-8 string -> UTF-16 bytes.
static uint32_t utf8_to_utf16(Avm2Context* ctx, const Avm2String* s, int little,
                              uint8_t** out_bytes)
{
	uint8_t* buf = avm2_alloc(ctx, s->len * 2 + 4);
	uint32_t out = 0;
	uint32_t i = 0;
	const uint8_t* b = (const uint8_t*) s->utf8;
	while (i < s->len)
	{
		uint32_t consumed;
		uint32_t len = utf8_seq_len(b + i, s->len - i, &consumed);
		uint32_t cp = 0xFFFD;
		if (len == 1) cp = b[i];
		else if (len == 2) cp = ((b[i] & 0x1Fu) << 6) | (b[i + 1] & 0x3F);
		else if (len == 3)
		{
			cp = ((b[i] & 0x0Fu) << 12) | ((b[i + 1] & 0x3Fu) << 6)
			     | (b[i + 2] & 0x3F);
		}
		else if (len == 4)
		{
			cp = ((b[i] & 0x07u) << 18) | ((b[i + 1] & 0x3Fu) << 12)
			     | ((b[i + 2] & 0x3Fu) << 6) | (b[i + 3] & 0x3F);
		}
		i += (len > 0) ? len : consumed;
		uint16_t units[2];
		uint32_t un = 1;
		if (cp >= 0x10000)
		{
			cp -= 0x10000;
			units[0] = (uint16_t) (0xD800 + (cp >> 10));
			units[1] = (uint16_t) (0xDC00 + (cp & 0x3FF));
			un = 2;
		}
		else
		{
			units[0] = (uint16_t) cp;
		}
		for (uint32_t k = 0; k < un; k++)
		{
			if (little)
			{
				buf[out++] = (uint8_t) units[k];
				buf[out++] = (uint8_t) (units[k] >> 8);
			}
			else
			{
				buf[out++] = (uint8_t) (units[k] >> 8);
				buf[out++] = (uint8_t) units[k];
			}
		}
	}
	*out_bytes = buf;
	return out;
}

// ---------------------------------------------------------------------------
// Natives
// ---------------------------------------------------------------------------

static Avm2ByteArrayExt* this_ba(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = avm2_bytearray_ext_of(act->this_val);
	if (ba == NULL)
	{
		avm2_throw_error(act->ctx, act->ctx->builtins.type_error_class,
		                 "Error #1004: Method ByteArray was invoked on an "
		                 "incompatible object.");
	}
	return ba;
}

static Avm2Value arg_or_undef(Avm2Activation* act, uint32_t i)
{
	return (i < act->argc) ? act->args[i] : avm2_undefined();
}

// get_string_non_null: null/undefined -> error 2007.
static const Avm2String* arg_string_non_null(Avm2Activation* act, uint32_t i,
                                             const char* pname)
{
	Avm2Value v = arg_or_undef(act, i);
	if (v.kind == AVM2_VALUE_NULL || v.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(act->ctx, pname);
	}
	return avm2_coerce_to_string(act->ctx, v);
}

static Avm2Value ba_get_length(Avm2Activation* act)
{
	return avm2_uint_value(this_ba(act)->len);
}

static Avm2Value ba_set_length_native(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	ba_set_length(act->ctx, ba, avm2_coerce_to_u32(act->ctx, arg_or_undef(act, 0)));
	return avm2_undefined();
}

static Avm2Value ba_get_position(Avm2Activation* act)
{
	return avm2_uint_value(this_ba(act)->position);
}

static Avm2Value ba_set_position(Avm2Activation* act)
{
	this_ba(act)->position = avm2_coerce_to_u32(act->ctx, arg_or_undef(act, 0));
	return avm2_undefined();
}

static Avm2Value ba_get_bytes_available(Avm2Activation* act)
{
	return avm2_uint_value(ba_bytes_available(this_ba(act)));
}

static Avm2Value ba_get_endian(Avm2Activation* act)
{
	return avm2_string(avm2_string_from_literal(
		act->ctx, this_ba(act)->endian_little ? "littleEndian" : "bigEndian"));
}

static Avm2Value ba_set_endian(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	const Avm2String* s = arg_string_non_null(act, 0, "endian");
	if (s->len == 9 && memcmp(s->utf8, "bigEndian", 9) == 0)
	{
		ba->endian_little = 0;
	}
	else if (s->len == 12 && memcmp(s->utf8, "littleEndian", 12) == 0)
	{
		ba->endian_little = 1;
	}
	else
	{
		throw_2008(act->ctx, "endian");
	}
	return avm2_undefined();
}

static Avm2Value ba_get_object_encoding(Avm2Activation* act)
{
	return avm2_uint_value(this_ba(act)->object_encoding);
}

static Avm2Value ba_set_object_encoding(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	uint32_t enc = avm2_coerce_to_u32(act->ctx, arg_or_undef(act, 0));
	if (enc == 0 || enc == 3)
	{
		ba->object_encoding = (uint8_t) enc;
	}
	else
	{
		throw_2008(act->ctx, "objectEncoding");
	}
	return avm2_undefined();
}

static Avm2Value ba_static_get_default_encoding(Avm2Activation* act)
{
	(void) act;
	return avm2_uint_value(avm2_get_context()->bytearray_default_encoding);
}

static Avm2Value ba_static_set_default_encoding(Avm2Activation* act)
{
	uint32_t enc = avm2_coerce_to_u32(act->ctx, arg_or_undef(act, 0));
	if (enc == 0 || enc == 3)
	{
		avm2_get_context()->bytearray_default_encoding = (uint8_t) enc;
	}
	return avm2_undefined();
}

static Avm2Value ba_clear(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	ba->len = 0;
	ba->position = 0;
	return avm2_undefined();
}

static Avm2Value ba_to_string(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	const uint8_t* b = ba->bytes;
	uint32_t n = ba->len;
	if (n >= 3 && b[0] == 0xEF && b[1] == 0xBB && b[2] == 0xBF)
	{
		return avm2_string(avm_utf8_lenient(ctx, b + 3, n - 3));
	}
	if (n >= 2 && b[0] == 0xFF && b[1] == 0xFE)
	{
		return avm2_string(utf16_to_utf8(ctx, b + 2, n - 2, 1));
	}
	if (n >= 2 && b[0] == 0xFE && b[1] == 0xFF)
	{
		return avm2_string(utf16_to_utf8(ctx, b + 2, n - 2, 0));
	}
	return avm2_string(avm_utf8_lenient(ctx, b, n));
}

// --- scalar reads ---

static Avm2Value ba_read_boolean(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	const uint8_t* p = ba_read_bytes(act->ctx, ba, 1);
	return avm2_bool(p[0] != 0);
}

static Avm2Value ba_read_byte(Avm2Activation* act)
{
	const uint8_t* p = ba_read_bytes(act->ctx, this_ba(act), 1);
	return avm2_integer((int8_t) p[0]);
}

static Avm2Value ba_read_unsigned_byte(Avm2Activation* act)
{
	const uint8_t* p = ba_read_bytes(act->ctx, this_ba(act), 1);
	return avm2_integer(p[0]);
}

static Avm2Value ba_read_short(Avm2Activation* act)
{
	return avm2_integer((int16_t) ba_read_u16(act->ctx, this_ba(act)));
}

static Avm2Value ba_read_unsigned_short(Avm2Activation* act)
{
	return avm2_integer(ba_read_u16(act->ctx, this_ba(act)));
}

static Avm2Value ba_read_int(Avm2Activation* act)
{
	return avm2_integer((int32_t) ba_read_u32(act->ctx, this_ba(act)));
}

static Avm2Value ba_read_unsigned_int(Avm2Activation* act)
{
	return avm2_uint_value(ba_read_u32(act->ctx, this_ba(act)));
}

static Avm2Value ba_read_float(Avm2Activation* act)
{
	uint32_t bits = ba_read_u32(act->ctx, this_ba(act));
	float f;
	memcpy(&f, &bits, 4);
	return avm2_number((double) f);
}

static Avm2Value ba_read_double(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	uint8_t be[8];
	ba_read_scalar(act->ctx, ba, be, 8);
	uint64_t bits = 0;
	for (int i = 0; i < 8; i++) bits = (bits << 8) | be[i];
	double d;
	memcpy(&d, &bits, 8);
	return avm2_number(d);
}

// --- scalar writes ---

static Avm2Value ba_write_boolean(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	uint8_t v = avm2_coerce_to_boolean(arg_or_undef(act, 0)) ? 1 : 0;
	ba_write_bytes(act->ctx, ba, &v, 1);
	return avm2_undefined();
}

static Avm2Value ba_write_byte(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	uint8_t v = (uint8_t) avm2_coerce_to_i32(act->ctx, arg_or_undef(act, 0));
	ba_write_bytes(act->ctx, ba, &v, 1);
	return avm2_undefined();
}

static Avm2Value ba_write_short(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	ba_write_u16(act->ctx, ba,
	             (uint16_t) avm2_coerce_to_i32(act->ctx, arg_or_undef(act, 0)));
	return avm2_undefined();
}

static Avm2Value ba_write_int(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	ba_write_u32(act->ctx, ba,
	             (uint32_t) avm2_coerce_to_i32(act->ctx, arg_or_undef(act, 0)));
	return avm2_undefined();
}

static Avm2Value ba_write_unsigned_int(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	ba_write_u32(act->ctx, ba, avm2_coerce_to_u32(act->ctx, arg_or_undef(act, 0)));
	return avm2_undefined();
}

static Avm2Value ba_write_float(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	float f = (float) avm2_coerce_to_number(act->ctx, arg_or_undef(act, 0));
	uint32_t bits;
	memcpy(&bits, &f, 4);
	ba_write_u32(act->ctx, ba, bits);
	return avm2_undefined();
}

static Avm2Value ba_write_double(Avm2Activation* act)
{
	Avm2ByteArrayExt* ba = this_ba(act);
	double d = avm2_coerce_to_number(act->ctx, arg_or_undef(act, 0));
	uint64_t bits;
	memcpy(&bits, &d, 8);
	uint8_t be[8];
	for (int i = 0; i < 8; i++) be[i] = (uint8_t) (bits >> (56 - i * 8));
	ba_write_scalar(act->ctx, ba, be, 8);
	return avm2_undefined();
}

// --- bulk transfer ---

static Avm2Value ba_write_bytes_native(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	Avm2Value arg0 = arg_or_undef(act, 0);
	if (arg0.kind == AVM2_VALUE_NULL || arg0.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(ctx, "bytes");
	}
	Avm2ByteArrayExt* src = avm2_bytearray_ext_of(arg0);
	if (src == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #1034: Type Coercion failed: cannot convert "
		                 "value to flash.utils.ByteArray.");
	}
	uint32_t offset = avm2_coerce_to_u32(ctx, arg_or_undef(act, 1));
	uint32_t length = avm2_coerce_to_u32(ctx, arg_or_undef(act, 2));
	uint32_t amnt = (length != 0)
		? length
		: (src->len > offset ? src->len - offset : 0);
	if (src == ba)
	{
		// Same array: validate the source range then memmove within.
		if ((uint64_t) offset + amnt > ba->len) throw_eof(ctx);
		uint32_t pos = ba->position;
		if ((uint64_t) pos + amnt > 0xFFFFFFFFull) throw_2006(ctx);
		if (ba->len < pos + amnt) ba_set_length(ctx, ba, pos + amnt);
		memmove(ba->bytes + pos, ba->bytes + offset, amnt);
		ba->position += amnt;
	}
	else
	{
		const uint8_t* p = ba_read_at(ctx, src, amnt, offset);
		ba_write_bytes(ctx, ba, p, amnt);
	}
	return avm2_undefined();
}

static Avm2Value ba_read_bytes_native(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	Avm2Value arg0 = arg_or_undef(act, 0);
	if (arg0.kind == AVM2_VALUE_NULL || arg0.kind == AVM2_VALUE_UNDEFINED)
	{
		throw_2007(ctx, "bytes");
	}
	Avm2ByteArrayExt* dst = avm2_bytearray_ext_of(arg0);
	if (dst == NULL)
	{
		avm2_throw_error(ctx, ctx->builtins.type_error_class,
		                 "Error #1034: Type Coercion failed: cannot convert "
		                 "value to flash.utils.ByteArray.");
	}
	uint32_t offset = avm2_coerce_to_u32(ctx, arg_or_undef(act, 1));
	uint32_t length = avm2_coerce_to_u32(ctx, arg_or_undef(act, 2));
	uint32_t amnt = (length != 0) ? length : ba_bytes_available(ba);
	if (dst == ba)
	{
		uint32_t pos = ba->position;
		if ((uint64_t) pos + amnt > ba->len) throw_eof(ctx);
		if ((uint64_t) offset + amnt > 0xFFFFFFFFull) throw_2006(ctx);
		if (ba->len < offset + amnt) ba_set_length(ctx, ba, offset + amnt);
		memmove(ba->bytes + offset, ba->bytes + pos, amnt);
	}
	else
	{
		const uint8_t* p = ba_read_bytes(ctx, ba, amnt);
		ba_write_at(ctx, dst, p, amnt, offset);
	}
	return avm2_undefined();
}

// --- strings ---

static Avm2Value ba_write_utf(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	const Avm2String* s = arg_string_non_null(act, 0, "value");
	if (s->len > 0xFFFF) throw_2006(ctx);
	ba_write_u16(ctx, ba, (uint16_t) s->len);
	ba_write_bytes(ctx, ba, (const uint8_t*) s->utf8, s->len);
	return avm2_undefined();
}

static Avm2Value ba_read_utf(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	uint16_t len = ba_read_u16(ctx, ba);
	const uint8_t* p = ba_read_bytes(ctx, ba, len);
	return avm2_string(utf_bytes_to_string(ctx, p, len));
}

static Avm2Value ba_write_utf_bytes(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	const Avm2String* s = arg_string_non_null(act, 0, "value");
	ba_write_bytes(ctx, ba, (const uint8_t*) s->utf8, s->len);
	return avm2_undefined();
}

static Avm2Value ba_read_utf_bytes(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	uint32_t len = avm2_coerce_to_u32(ctx, arg_or_undef(act, 0));
	const uint8_t* p = ba_read_bytes(ctx, ba, len);
	return avm2_string(utf_bytes_to_string(ctx, p, len));
}

static Avm2Value ba_write_multi_byte(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	const Avm2String* s = arg_string_non_null(act, 0, "value");
	const Avm2String* label = arg_string_non_null(act, 1, "charSet");
	const char* iconv_name = NULL;
	int cs = charset_classify(label, &iconv_name);
	uint8_t* bytes = (uint8_t*) s->utf8;
	uint32_t n = s->len;
	if (cs == CS_UTF16LE || cs == CS_UTF16BE)
	{
		n = utf8_to_utf16(ctx, s, cs == CS_UTF16LE, &bytes);
	}
#ifndef __EMSCRIPTEN__
	else if (cs == CS_ICONV)
	{
		n = iconv_encode(ctx, iconv_name, s, &bytes);
	}
#endif
	ba_write_bytes(ctx, ba, bytes, n);
	return avm2_undefined();
}

static Avm2Value ba_read_multi_byte(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	uint32_t len = avm2_coerce_to_u32(ctx, arg_or_undef(act, 0));
	const Avm2String* label = arg_string_non_null(act, 1, "charSet");
	const uint8_t* p = ba_read_bytes(ctx, ba, len);
	const char* iconv_name = NULL;
	int cs = charset_classify(label, &iconv_name);
	const Avm2String* s;
	if (cs == CS_UTF16LE || cs == CS_UTF16BE)
	{
		s = utf16_to_utf8(ctx, p, len, cs == CS_UTF16LE);
	}
#ifndef __EMSCRIPTEN__
	else if (cs == CS_ICONV)
	{
		s = iconv_decode(ctx, iconv_name, p, len);
	}
#endif
	else
	{
		s = utf8_lossy(ctx, p, len);
	}
	// Flash truncates at the first NUL after checking the byte length.
	for (uint32_t i = 0; i < s->len; i++)
	{
		if (s->utf8[i] == '\0')
		{
			return avm2_string(avm2_string_new(ctx, s->utf8, i));
		}
	}
	return avm2_string(s);
}

// --- compression ---

enum { ALG_ZLIB, ALG_DEFLATE, ALG_LZMA };

static int parse_algorithm(Avm2Activation* act, const Avm2String* s)
{
	if (s->len == 4 && memcmp(s->utf8, "zlib", 4) == 0) return ALG_ZLIB;
	if (s->len == 7 && memcmp(s->utf8, "deflate", 7) == 0) return ALG_DEFLATE;
	if (s->len == 4 && memcmp(s->utf8, "lzma", 4) == 0) return ALG_LZMA;
	throw_2058(act->ctx);
}

static Avm2Value ba_compress(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	const Avm2String* s = (act->argc > 0)
		? arg_string_non_null(act, 0, "algorithm")
		: avm2_string_from_literal(ctx, "zlib");
	int alg = parse_algorithm(act, s);
	uint8_t* out = NULL;
	uint32_t out_len = 0;
	if (alg != ALG_LZMA && ba->len > 0)
	{
		z_stream strm;
		memset(&strm, 0, sizeof(strm));
		int wbits = (alg == ALG_ZLIB) ? 15 : -15;
		if (deflateInit2(&strm, 9, Z_DEFLATED, wbits, 8, Z_DEFAULT_STRATEGY) == Z_OK)
		{
			uLong bound = deflateBound(&strm, ba->len);
			out = avm2_alloc(ctx, (uint32_t) bound);
			strm.next_in = ba->bytes;
			strm.avail_in = ba->len;
			strm.next_out = out;
			strm.avail_out = (uInt) bound;
			if (deflate(&strm, Z_FINISH) == Z_STREAM_END)
			{
				out_len = (uint32_t) strm.total_out;
			}
			else
			{
				out_len = 0;  // Ruffle: empty buffer on error
			}
			deflateEnd(&strm);
		}
	}
	else if (alg != ALG_LZMA)
	{
		// Compressing an empty buffer still yields a valid stream.
		z_stream strm;
		memset(&strm, 0, sizeof(strm));
		int wbits = (alg == ALG_ZLIB) ? 15 : -15;
		if (deflateInit2(&strm, 9, Z_DEFLATED, wbits, 8, Z_DEFAULT_STRATEGY) == Z_OK)
		{
			out = avm2_alloc(ctx, 64);
			strm.next_out = out;
			strm.avail_out = 64;
			if (deflate(&strm, Z_FINISH) == Z_STREAM_END)
			{
				out_len = (uint32_t) strm.total_out;
			}
			deflateEnd(&strm);
		}
	}
	// LZMA: not compiled in -> empty result (Ruffle warns and clears).
	ba->len = 0;
	ba->position = 0;
	if (out_len > 0) ba_write_bytes(ctx, ba, out, out_len);
	ba->position = ba->len;
	return avm2_undefined();
}

static Avm2Value ba_uncompress(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2ByteArrayExt* ba = this_ba(act);
	const Avm2String* s = (act->argc > 0)
		? arg_string_non_null(act, 0, "algorithm")
		: avm2_string_from_literal(ctx, "zlib");
	int alg = parse_algorithm(act, s);
	if (alg == ALG_LZMA) throw_2058(ctx);
	// flate2 succeeds with empty output on an empty input stream.
	if (ba->len == 0)
	{
		ba->position = 0;
		return avm2_undefined();
	}
	z_stream strm;
	memset(&strm, 0, sizeof(strm));
	int wbits = (alg == ALG_ZLIB) ? 15 : -15;
	if (inflateInit2(&strm, wbits) != Z_OK) throw_2058(ctx);
	uint32_t cap = ba->len * 4 + 64;
	uint8_t* out = avm2_alloc(ctx, cap);
	uint32_t out_len = 0;
	strm.next_in = ba->bytes;
	strm.avail_in = ba->len;
	int ok = 0;
	for (;;)
	{
		strm.next_out = out + out_len;
		strm.avail_out = cap - out_len;
		int rc = inflate(&strm, Z_NO_FLUSH);
		out_len = (uint32_t) strm.total_out;
		if (rc == Z_STREAM_END)
		{
			ok = 1;
			break;
		}
		if (rc == Z_OK || rc == Z_BUF_ERROR)
		{
			if (strm.avail_out == 0)
			{
				uint8_t* grown = avm2_alloc(ctx, cap * 2);
				memcpy(grown, out, out_len);
				out = grown;
				cap *= 2;
				continue;
			}
			// No progress possible (truncated stream).
			break;
		}
		break;
	}
	inflateEnd(&strm);
	if (!ok) throw_2058(ctx);
	ba->len = 0;
	ba->position = 0;
	if (out_len > 0) ba_write_bytes(ctx, ba, out, out_len);
	ba->position = 0;
	return avm2_undefined();
}

static Avm2Value ba_deflate(Avm2Activation* act)
{
	Avm2Value arg = avm2_string(avm2_string_from_literal(act->ctx, "deflate"));
	Avm2Activation sub = *act;
	sub.args = &arg;
	sub.argc = 1;
	return ba_compress(&sub);
}

static Avm2Value ba_inflate(Avm2Activation* act)
{
	Avm2Value arg = avm2_string(avm2_string_from_literal(act->ctx, "deflate"));
	Avm2Activation sub = *act;
	sub.args = &arg;
	sub.argc = 1;
	return ba_uncompress(&sub);
}

// readObject/writeObject (AMF) live in avm2_amf.c.
Avm2Value avm2_amf_read_object(Avm2Activation* act);
Avm2Value avm2_amf_write_object(Avm2Activation* act);

// ---------------------------------------------------------------------------
// Registration
// ---------------------------------------------------------------------------

static void ba_native_init(Avm2Context* ctx, Avm2Object* obj)
{
	(void) ctx;
	Avm2ByteArrayExt* ba = (Avm2ByteArrayExt*) obj->native_ext;
	ba->object_encoding = avm2_get_context()->bytearray_default_encoding;
}

static Avm2Value ba_proto_to_json(Avm2Activation* act)
{
	return avm2_string(avm2_string_from_literal(act->ctx, "ByteArray"));
}

static void ba_add_getset(Avm2Context* ctx, Avm2Class* cls, const char* name,
                          Avm2MethodFn getter, Avm2MethodFn setter)
{
	Avm2PropEntry e;
	memset(&e, 0, sizeof(e));
	e.key = avm2_public_key(name, (uint32_t) strlen(name));
	e.kind = AVM2_PROP_GETSET;
	e.method.fn = getter;
	e.method.debug_name = name;
	e.setter.fn = setter;
	e.setter.debug_name = name;
	e.defining_class = cls;
	avm2_vtable_append(ctx, &cls->ivtable, &e);
}

void avm2_register_bytearray(Avm2Context* ctx)
{
	Avm2Builtins* b = &ctx->builtins;
	ctx->bytearray_default_encoding = 3;  // AMF3 (SWF9+ default)

	Avm2Class* cls = avm2_builtin_class(ctx, "flash.utils", "ByteArray",
	                                    b->object_class);
	b->bytearray_class = cls;
	cls->flags |= AVM2_CLASS_FLAG_SEALED;
	cls->native_ext_size = sizeof(Avm2ByteArrayExt);
	cls->native_init = ba_native_init;

	ba_add_getset(ctx, cls, "length", ba_get_length, ba_set_length_native);
	ba_add_getset(ctx, cls, "position", ba_get_position, ba_set_position);
	ba_add_getset(ctx, cls, "endian", ba_get_endian, ba_set_endian);
	ba_add_getset(ctx, cls, "objectEncoding", ba_get_object_encoding,
	              ba_set_object_encoding);
	avm2_builtin_add_getter(ctx, cls, "bytesAvailable", ba_get_bytes_available);

	// Static defaultObjectEncoding accessor pair on the class object.
	{
		Avm2VTable* vt = (Avm2VTable*) cls->class_object->vtable;
		if (vt == NULL)
		{
			vt = avm2_alloc(ctx, sizeof(Avm2VTable));
			memset(vt, 0, sizeof(Avm2VTable));
			cls->class_object->vtable = vt;
		}
		Avm2PropEntry e;
		memset(&e, 0, sizeof(e));
		e.key = avm2_public_key("defaultObjectEncoding", 21);
		e.kind = AVM2_PROP_GETSET;
		e.method.fn = ba_static_get_default_encoding;
		e.method.debug_name = "get defaultObjectEncoding";
		e.setter.fn = ba_static_set_default_encoding;
		e.setter.debug_name = "set defaultObjectEncoding";
		e.defining_class = cls;
		avm2_vtable_append(ctx, vt, &e);
	}

	avm2_builtin_add_method(ctx, cls, "clear", ba_clear);
	avm2_builtin_add_method(ctx, cls, "compress", ba_compress);
	avm2_builtin_add_method(ctx, cls, "uncompress", ba_uncompress);
	avm2_builtin_add_method(ctx, cls, "deflate", ba_deflate);
	avm2_builtin_add_method(ctx, cls, "inflate", ba_inflate);
	avm2_builtin_add_method(ctx, cls, "toString", ba_to_string);
	avm2_builtin_add_method(ctx, cls, "readBoolean", ba_read_boolean);
	avm2_builtin_add_method(ctx, cls, "readByte", ba_read_byte);
	avm2_builtin_add_method(ctx, cls, "readUnsignedByte", ba_read_unsigned_byte);
	avm2_builtin_add_method(ctx, cls, "readShort", ba_read_short);
	avm2_builtin_add_method(ctx, cls, "readUnsignedShort", ba_read_unsigned_short);
	avm2_builtin_add_method(ctx, cls, "readInt", ba_read_int);
	avm2_builtin_add_method(ctx, cls, "readUnsignedInt", ba_read_unsigned_int);
	avm2_builtin_add_method(ctx, cls, "readFloat", ba_read_float);
	avm2_builtin_add_method(ctx, cls, "readDouble", ba_read_double);
	avm2_builtin_add_method(ctx, cls, "readBytes", ba_read_bytes_native);
	avm2_builtin_add_method(ctx, cls, "readUTF", ba_read_utf);
	avm2_builtin_add_method(ctx, cls, "readUTFBytes", ba_read_utf_bytes);
	avm2_builtin_add_method(ctx, cls, "readMultiByte", ba_read_multi_byte);
	avm2_builtin_add_method(ctx, cls, "readObject", avm2_amf_read_object);
	avm2_builtin_add_method(ctx, cls, "writeBoolean", ba_write_boolean);
	avm2_builtin_add_method(ctx, cls, "writeByte", ba_write_byte);
	avm2_builtin_add_method(ctx, cls, "writeShort", ba_write_short);
	avm2_builtin_add_method(ctx, cls, "writeInt", ba_write_int);
	avm2_builtin_add_method(ctx, cls, "writeUnsignedInt", ba_write_unsigned_int);
	avm2_builtin_add_method(ctx, cls, "writeFloat", ba_write_float);
	avm2_builtin_add_method(ctx, cls, "writeDouble", ba_write_double);
	avm2_builtin_add_method(ctx, cls, "writeBytes", ba_write_bytes_native);
	avm2_builtin_add_method(ctx, cls, "writeUTF", ba_write_utf);
	avm2_builtin_add_method(ctx, cls, "writeUTFBytes", ba_write_utf_bytes);
	avm2_builtin_add_method(ctx, cls, "writeMultiByte", ba_write_multi_byte);
	avm2_builtin_add_method(ctx, cls, "writeObject", avm2_amf_write_object);

	avm2_proto_add_function(ctx, cls->prototype_obj, "toJSON", ba_proto_to_json);
	avm2_proto_add_function(ctx, cls->prototype_obj, "toString", ba_to_string);

	// flash.utils.Endian + flash.utils.CompressionAlgorithm constants.
	{
		Avm2Class* endian = avm2_builtin_class(ctx, "flash.utils", "Endian",
		                                       b->object_class);
		avm2_builtin_add_static_const(ctx, endian, "BIG_ENDIAN",
			avm2_string(avm2_string_from_literal(ctx, "bigEndian")));
		avm2_builtin_add_static_const(ctx, endian, "LITTLE_ENDIAN",
			avm2_string(avm2_string_from_literal(ctx, "littleEndian")));
		Avm2Class* ca = avm2_builtin_class(ctx, "flash.utils",
		                                   "CompressionAlgorithm", b->object_class);
		avm2_builtin_add_static_const(ctx, ca, "ZLIB",
			avm2_string(avm2_string_from_literal(ctx, "zlib")));
		avm2_builtin_add_static_const(ctx, ca, "DEFLATE",
			avm2_string(avm2_string_from_literal(ctx, "deflate")));
		avm2_builtin_add_static_const(ctx, ca, "LZMA",
			avm2_string(avm2_string_from_literal(ctx, "lzma")));
	}
}

// --- Public helpers for the BitmapData module (avm2_bitmap.c) ---
void avm2_bytearray_write_uint_public(Avm2Context* ctx, Avm2ByteArrayExt* ba,
                                      uint32_t v)
{
	ba_write_u32(ctx, ba, v);
}
uint32_t avm2_bytearray_read_uint_public(Avm2Context* ctx, Avm2ByteArrayExt* ba)
{
	return ba_read_u32(ctx, ba);
}
