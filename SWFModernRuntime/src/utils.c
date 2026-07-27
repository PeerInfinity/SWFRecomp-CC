#include <string.h>

#include <heap.h>
#include <utils.h>

void grow_ptr(SWFAppContext* app_context, char** ptr, size_t* capacity_ptr, size_t elem_size)
{
	char* data = *ptr;
	size_t capacity = *capacity_ptr;
	size_t old_data_size = capacity*elem_size;
	size_t new_data_size = old_data_size << 1;

	char* new_data = HALLOC(new_data_size);

	memcpy(new_data, data, old_data_size);
	// Zero the new region so expanded display_list/dictionary entries are clean
	memset(new_data + old_data_size, 0, new_data_size - old_data_size);

	FREE(data);

	*ptr = new_data;
	*capacity_ptr = capacity << 1;
}

#if defined(_MSC_VER)
// Microsoft

#include <windows.h>
#include <Winbase.h>

u32 get_elapsed_ms()
{
	return (u32) GetTickCount();
}

int getpagesize()
{
	SYSTEM_INFO si;
	GetSystemInfo(&si);

	return si.dwPageSize;
}

char* vmem_reserve(size_t size)
{
	return VirtualAlloc(NULL, size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
}

void vmem_release(char* addr, size_t size)
{
	VirtualFree(addr, 0, MEM_RELEASE);
}

#elif defined(__wasi__)
// WASI (no mmap, use malloc/free; no POSIX clocks)

#include <stdlib.h>

u32 get_elapsed_ms()
{
	return 0;  // Timing not needed for trace-only WASI builds
}

char* vmem_reserve(size_t size)
{
	return (char*)malloc(size);
}

void vmem_release(char* addr, size_t size)
{
	(void)size;
	free(addr);
}

#elif defined(__GNUC__)
// GCC

#include <stdlib.h>
#include <time.h>
#include <sys/mman.h>

u32 get_elapsed_ms()
{
	struct timespec now;
	clock_gettime(CLOCK_MONOTONIC, &now);
	return (now.tv_sec)*1000 + (now.tv_nsec)/1000000;
}

char* vmem_reserve(size_t size)
{
	// mmap failure is MAP_FAILED ((void*)-1), NOT NULL — callers (heap_init)
	// check for NULL, so translate. Un-translated, a failed reserve flowed
	// 0xffffffff into o1heapInit (seen when the wasm32 arena briefly exceeded
	// emscripten's mmap ceiling).
	void* p = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
	return p == MAP_FAILED ? NULL : (char*) p;
}

void vmem_release(char* addr, size_t size)
{
	munmap(addr, size);
}

#endif

// ---------------------------------------------------------------------------
// Ruffle test-navigator request log (see utils.h)
// ---------------------------------------------------------------------------

#if SWF_LOG_FETCH_ENABLED

#include <stdio.h>
#include <stdlib.h>

// A block under construction. Plain malloc, not HALLOC: this is test-only
// scaffolding and must not perturb the runtime arena the tests measure.
typedef struct LogBuf
{
	char* data;
	size_t len;
	size_t cap;
} LogBuf;

static void logbuf_reserve(LogBuf* b, size_t extra)
{
	if (b->len + extra + 1 <= b->cap) return;
	size_t cap = b->cap ? b->cap : 256;
	while (cap < b->len + extra + 1) cap <<= 1;
	char* nd = (char*) realloc(b->data, cap);
	if (nd == NULL) return;
	b->data = nd;
	b->cap = cap;
}

// Append raw text with the trace log's two normalizations (a NUL byte
// disappears, a CR becomes LF) — the same ones native_trace applies, because
// this lands in the identical output stream.
static void logbuf_put(LogBuf* b, const char* s, size_t n)
{
	if (s == NULL) return;
	logbuf_reserve(b, n);
	// A failed realloc leaves cap short — drop the append rather than run past
	// the end of the block we do have.
	if (b->data == NULL || b->len + n + 1 > b->cap) return;
	for (size_t i = 0; i < n; i++)
	{
		char c = s[i];
		if (c == '\0') continue;
		b->data[b->len++] = (c == '\r') ? '\n' : c;
	}
	b->data[b->len] = '\0';
}

static void logbuf_lit(LogBuf* b, const char* s)
{
	logbuf_put(b, s, strlen(s));
}

// Rust's `{:02X?}` over a byte slice: "[41, 3D, 62]" (empty slice -> "[]").
static void logbuf_hex_slice(LogBuf* b, const unsigned char* body, size_t n)
{
	logbuf_lit(b, "[");
	for (size_t i = 0; i < n; i++)
	{
		char tmp[8];
		int m = snprintf(tmp, sizeof(tmp), i ? ", %02X" : "%02X", body[i]);
		logbuf_put(b, tmp, (size_t) m);
	}
	logbuf_lit(b, "]");
}

#define SWF_LOG_FETCH_MAX_QUEUED 64
static char* g_fetch_log_queue[SWF_LOG_FETCH_MAX_QUEUED];
static size_t g_fetch_log_count;

void swf_log_fetch_queue(const char* url, size_t url_len,
                         const char* method, size_t method_len,
                         const SwfLogPair* headers, size_t header_count,
                         const char* mime, size_t mime_len,
                         const unsigned char* body, size_t body_len,
                         int has_body, int body_is_form)
{
	if (g_fetch_log_count >= SWF_LOG_FETCH_MAX_QUEUED) return;

	LogBuf b;
	b.data = NULL; b.len = 0; b.cap = 0;
	logbuf_lit(&b, "Navigator::fetch:\n  URL: ");
	logbuf_put(&b, url, url_len);
	logbuf_lit(&b, "\n  Method: ");
	logbuf_put(&b, method, method_len);
	if (header_count > 0)
	{
		// Ruffle emits the header list as ONE trace entry whose first line is
		// "  Headers:" — hence the entries themselves carry no indent.
		logbuf_lit(&b, "\n  Headers:");
		for (size_t i = 0; i < header_count; i++)
		{
			logbuf_lit(&b, "\n");
			logbuf_put(&b, headers[i].name, headers[i].name_len);
			logbuf_lit(&b, ": ");
			logbuf_put(&b, headers[i].value, headers[i].value_len);
		}
	}
	if (has_body)
	{
		logbuf_lit(&b, "\n  Mime-Type: ");
		logbuf_put(&b, mime, mime_len);
		logbuf_lit(&b, "\n  Body: ");
		if (body_is_form) logbuf_put(&b, (const char*) body, body_len);
		else logbuf_hex_slice(&b, body, body_len);
	}
	logbuf_lit(&b, "\n");
	if (b.data != NULL) g_fetch_log_queue[g_fetch_log_count++] = b.data;
}

int swf_log_fetch_pending(void)
{
	return g_fetch_log_count > 0;
}

void swf_log_fetch_flush(void)
{
	for (size_t i = 0; i < g_fetch_log_count; i++)
	{
		fputs(g_fetch_log_queue[i], stdout);
		free(g_fetch_log_queue[i]);
		g_fetch_log_queue[i] = NULL;
	}
	g_fetch_log_count = 0;
}

// normalize_navigate_target (backend/navigator.rs): "_blank" is matched
// case-insensitively AND with the leading underscore optional, so "blank",
// "BLANK" and "_BlAnK" all mean "_blank". Every other target — including the
// other reserved ones (_self/_parent/_top) — passes through untouched.
static int target_is_blank(const char* t, size_t n)
{
	static const char blank[5] = { 'b', 'l', 'a', 'n', 'k' };
	if (n > 0 && t[0] == '_') { t++; n--; }
	if (n != 5) return 0;
	for (size_t i = 0; i < 5; i++)
	{
		char c = t[i];
		if (c >= 'A' && c <= 'Z') c = (char) (c - 'A' + 'a');
		if (c != blank[i]) return 0;
	}
	return 1;
}

void swf_log_navigate(const char* url, size_t url_len,
                      const char* target, size_t target_len,
                      const char* method, size_t method_len,
                      const SwfLogPair* params, size_t param_count)
{
	if (target_is_blank(target, target_len))
	{
		target = "_blank";
		target_len = 6;
	}
	LogBuf b;
	b.data = NULL; b.len = 0; b.cap = 0;
	logbuf_lit(&b, "Navigator::navigate_to_url:\n  URL: ");
	logbuf_put(&b, url, url_len);
	logbuf_lit(&b, "\n  Target: ");
	logbuf_put(&b, target, target_len);
	if (method != NULL)
	{
		logbuf_lit(&b, "\n  Method: ");
		logbuf_put(&b, method, method_len);
		for (size_t i = 0; i < param_count; i++)
		{
			logbuf_lit(&b, "\n  Param: ");
			logbuf_put(&b, params[i].name, params[i].name_len);
			logbuf_lit(&b, "=");
			logbuf_put(&b, params[i].value, params[i].value_len);
		}
	}
	logbuf_lit(&b, "\n");
	if (b.data != NULL)
	{
		fputs(b.data, stdout);
		free(b.data);
	}
}

#else

void swf_log_fetch_queue(const char* url, size_t url_len,
                         const char* method, size_t method_len,
                         const SwfLogPair* headers, size_t header_count,
                         const char* mime, size_t mime_len,
                         const unsigned char* body, size_t body_len,
                         int has_body, int body_is_form)
{
	(void) url; (void) url_len; (void) method; (void) method_len;
	(void) headers; (void) header_count; (void) mime; (void) mime_len;
	(void) body; (void) body_len; (void) has_body; (void) body_is_form;
}

int swf_log_fetch_pending(void) { return 0; }
void swf_log_fetch_flush(void) { }

void swf_log_navigate(const char* url, size_t url_len,
                      const char* target, size_t target_len,
                      const char* method, size_t method_len,
                      const SwfLogPair* params, size_t param_count)
{
	(void) url; (void) url_len; (void) target; (void) target_len;
	(void) method; (void) method_len; (void) params; (void) param_count;
}

#endif
