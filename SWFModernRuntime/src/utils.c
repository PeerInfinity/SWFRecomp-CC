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

// TestNavigatorBackend::connect_socket logs before it looks at the socket
// script, so the block appears on EVERY connect — including the ones with no
// script behind them. Printed immediately (like navigate_to_url, unlike
// fetch): it is a plain synchronous backend call.
void swf_log_connect_socket(const char* host, size_t host_len, int port)
{
	LogBuf b;
	b.data = NULL; b.len = 0; b.cap = 0;
	logbuf_lit(&b, "Navigator::connect_socket\n    Host: ");
	logbuf_put(&b, host, host_len);
	logbuf_lit(&b, "; Port: ");
	{
		char tmp[16];
		int m = snprintf(tmp, sizeof(tmp), "%d", port);
		logbuf_put(&b, tmp, (size_t) m);
	}
	logbuf_lit(&b, "\n");
	if (b.data != NULL)
	{
		fputs(b.data, stdout);
		free(b.data);
	}
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

void swf_log_connect_socket(const char* host, size_t host_len, int port)
{
	(void) host; (void) host_len; (void) port;
}

void swf_log_navigate(const char* url, size_t url_len,
                      const char* target, size_t target_len,
                      const char* method, size_t method_len,
                      const SwfLogPair* params, size_t param_count)
{
	(void) url; (void) url_len; (void) target; (void) target_len;
	(void) method; (void) method_len; (void) params; (void) param_count;
}

#endif

// ---------------------------------------------------------------------------
// Scripted socket transport (see include/socket_events.h for the contract)
// ---------------------------------------------------------------------------
//
// The other half of the Ruffle test navigator: `socket.json` replay. Models
// TestNavigatorBackend::connect_socket without any of its async machinery —
// the spawned future becomes a per-connection cursor over the parsed script,
// the player->server channel becomes an outbox queue, and the server->player
// channel becomes one global action queue drained at the tick boundary. The
// blocking points (`Receive` / `WaitForDisconnect`) are simply "stop
// advancing the cursor and return".
//
// Plain malloc/free, like the LOG_FETCH buffers above: test-only scaffolding
// must not perturb the arena the runtime measures. Compiled unconditionally
// (not under SWF_LOG_FETCH_ENABLED) because both VMs' socket classes link
// against it in every build.

#include <stdio.h>
#include <stdlib.h>

#include <socket_events.h>

// --- script ---

enum { OP_SEND = 0, OP_RECV = 1, OP_DISCONNECT = 2, OP_WAITDISCONNECT = 3 };

typedef struct SockOp
{
	int kind;
	unsigned char* bytes;
	size_t len;
} SockOp;

static SockOp* g_script;
static size_t g_script_len;
static int g_script_loaded;
static int g_script_init_done;

static int sock_hex_nib(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	if (c >= 'a' && c <= 'f') return c - 'a' + 10;
	if (c >= 'A' && c <= 'F') return c - 'A' + 10;
	return -1;
}

// "0a14ff" -> 3 bytes. A malformed pair truncates rather than aborting; the
// preprocessor always emits well-formed hex.
static void sock_parse_hex(const char* s, unsigned char** out, size_t* out_len)
{
	size_t n = strlen(s) / 2;
	*out = NULL;
	*out_len = 0;
	if (n == 0) return;
	unsigned char* buf = (unsigned char*) malloc(n);
	if (buf == NULL) return;
	size_t k = 0;
	for (size_t i = 0; i < n; i++)
	{
		int hi = sock_hex_nib(s[i * 2]);
		int lo = sock_hex_nib(s[i * 2 + 1]);
		if (hi < 0 || lo < 0) break;
		buf[k++] = (unsigned char) ((hi << 4) | lo);
	}
	*out = buf;
	*out_len = k;
}

void swf_socket_events_load(const char* path)
{
	if (path == NULL || path[0] == '\0') return;
	FILE* f = fopen(path, "r");
	// The file's mere existence is the "connect() succeeds" signal, so a
	// zero-op script ([] in socket.json) still counts as loaded.
	if (f == NULL) return;
	g_script_loaded = 1;

	char line[8192];
	size_t cap = 0;
	while (fgets(line, sizeof(line), f) != NULL)
	{
		size_t l = strlen(line);
		while (l > 0 && (line[l - 1] == '\n' || line[l - 1] == '\r')) line[--l] = '\0';
		if (l == 0) continue;

		SockOp op;
		memset(&op, 0, sizeof(op));
		if (strncmp(line, "SEND", 4) == 0 && (line[4] == '\0' || line[4] == ' '))
		{
			op.kind = OP_SEND;
			if (line[4] == ' ') sock_parse_hex(line + 5, &op.bytes, &op.len);
		}
		else if (strncmp(line, "RECV", 4) == 0 && (line[4] == '\0' || line[4] == ' '))
		{
			op.kind = OP_RECV;
			if (line[4] == ' ') sock_parse_hex(line + 5, &op.bytes, &op.len);
		}
		else if (strcmp(line, "DISCONNECT") == 0)
			op.kind = OP_DISCONNECT;
		else if (strcmp(line, "WAITDISCONNECT") == 0)
			op.kind = OP_WAITDISCONNECT;
		else
			continue;

		if (g_script_len == cap)
		{
			size_t ncap = cap ? cap * 2 : 16;
			SockOp* ns = (SockOp*) realloc(g_script, ncap * sizeof(SockOp));
			if (ns == NULL) { free(op.bytes); break; }
			g_script = ns;
			cap = ncap;
		}
		g_script[g_script_len++] = op;
	}
	fclose(f);
}

void swf_socket_events_init(void)
{
	if (g_script_init_done) return;
	g_script_init_done = 1;
	const char* p = getenv("SWF_SOCKET_SCRIPT");
	if (p != NULL) swf_socket_events_load(p);
}

int swf_socket_script_loaded(void)
{
	swf_socket_events_init();
	return g_script_loaded;
}

// --- connections ---

typedef struct SockMsg
{
	unsigned char* bytes;
	size_t len;
} SockMsg;

typedef struct SockConn
{
	int in_use;
	int connected;      // Connect delivered, Close not yet
	int dead;           // socket removed (player close, or Close delivered)
	int sent_connect;   // the mock has queued its Connect action
	int failed;         // a script assertion failed: stop advancing
	size_t cursor;
	SockMsg* out;       // player -> server messages, FIFO
	size_t out_head, out_count, out_cap;
	void* target;
	SwfSocketDispatchFn dispatch;
} SockConn;

// avm1/xml_socket_connect_null opens four in one frame; nothing in the corpus
// comes near this ceiling.
#define MAX_SOCK_CONNS 32
static SockConn g_conns[MAX_SOCK_CONNS];
static int g_conn_count;

typedef struct SockAction
{
	int handle;
	int action;
	unsigned char* data;
	size_t len;
} SockAction;

static SockAction* g_sock_actions;
static size_t g_action_head, g_action_count, g_action_cap;

static SockConn* sock_conn_of(int handle)
{
	if (handle <= 0 || handle > g_conn_count) return NULL;
	SockConn* c = &g_conns[handle - 1];
	return c->in_use ? c : NULL;
}

static void sock_queue_action(int handle, int action,
                              const unsigned char* data, size_t len)
{
	if (g_action_count == g_action_cap)
	{
		size_t ncap = g_action_cap ? g_action_cap * 2 : 16;
		SockAction* na = (SockAction*) realloc(g_sock_actions,
		                                       ncap * sizeof(SockAction));
		if (na == NULL) return;
		g_sock_actions = na;
		g_action_cap = ncap;
	}
	SockAction* a = &g_sock_actions[g_action_count++];
	a->handle = handle;
	a->action = action;
	a->data = NULL;
	a->len = len;
	if (len > 0 && data != NULL)
	{
		a->data = (unsigned char*) malloc(len);
		if (a->data != NULL) memcpy(a->data, data, len);
		else a->len = 0;
	}
}

int swf_socket_connect(const char* host, int port, void* target,
                       SwfSocketDispatchFn dispatch)
{
	swf_log_connect_socket(host != NULL ? host : "",
	                       host != NULL ? strlen(host) : 0, port);

	// No script -> Ruffle's mock never spawns a future, so no Connect action
	// ever arrives and the socket stays shut. This is the branch that keeps
	// avm2/socket_errors (#2002 on every op) passing.
	if (!swf_socket_script_loaded()) return 0;
	if (g_conn_count >= MAX_SOCK_CONNS) return 0;

	SockConn* c = &g_conns[g_conn_count++];
	memset(c, 0, sizeof(*c));
	c->in_use = 1;
	c->target = target;
	c->dispatch = dispatch;
	return g_conn_count;
}

int swf_socket_is_connected(int handle)
{
	SockConn* c = sock_conn_of(handle);
	return (c != NULL && c->connected && !c->dead) ? 1 : 0;
}

void swf_socket_close(int handle)
{
	SockConn* c = sock_conn_of(handle);
	if (c == NULL || c->dead) return;
	// Ruffle removes the socket from its slotmap, which both drops the
	// player->server sender and makes every already-queued action for this
	// handle a no-op. Messages the player already flushed stay in the channel
	// and still satisfy a later `Receive` — hence the outbox is retained.
	c->dead = 1;
	c->connected = 0;
}

void swf_socket_send(int handle, const unsigned char* data, size_t len)
{
	SockConn* c = sock_conn_of(handle);
	if (c == NULL || c->dead) return;
	if (c->out_count == c->out_cap)
	{
		size_t ncap = c->out_cap ? c->out_cap * 2 : 8;
		SockMsg* nm = (SockMsg*) realloc(c->out, ncap * sizeof(SockMsg));
		if (nm == NULL) return;
		c->out = nm;
		c->out_cap = ncap;
	}
	SockMsg* m = &c->out[c->out_count++];
	m->bytes = NULL;
	m->len = len;
	if (len > 0)
	{
		m->bytes = (unsigned char*) malloc(len);
		if (m->bytes != NULL) memcpy(m->bytes, data, len);
		else m->len = 0;
	}
}

// --- tick: deliver, then pump ---

static void sock_deliver_actions(void)
{
	// Ruffle drains the channel into a Vec first and then walks it, so the
	// set delivered this tick is fixed at entry.
	size_t end = g_action_count;
	while (g_action_head < end)
	{
		SockAction* a = &g_sock_actions[g_action_head++];
		SockConn* c = sock_conn_of(a->handle);
		// Dead handle: skipped silently, including when the player closed the
		// socket inside an earlier handler in this very pass. That is what
		// drops the second queued Data in avm1/xml_socket_close_in_handler,
		// and why no onClose fires there.
		if (c != NULL && !c->dead)
		{
			switch (a->action)
			{
			case SWF_SOCKET_CONNECT:
				c->connected = 1;
				c->dispatch(c->target, SWF_SOCKET_CONNECT, NULL, 0);
				break;
			case SWF_SOCKET_DATA:
				c->dispatch(c->target, SWF_SOCKET_DATA, a->data, a->len);
				break;
			case SWF_SOCKET_CLOSE:
				c->connected = 0;
				c->dead = 1;
				c->dispatch(c->target, SWF_SOCKET_CLOSE, NULL, 0);
				break;
			default:
				break;
			}
		}
		free(a->data);
		a->data = NULL;
	}
	if (g_action_head == g_action_count)
	{
		g_action_head = 0;
		g_action_count = 0;
	}
}

static void sock_script_fail(SockConn* c, const char* why)
{
	c->failed = 1;
	fprintf(stderr, "socket.json replay: %s\n", why);
}

static void sock_pump_conn(int idx)
{
	SockConn* c = &g_conns[idx];
	if (!c->in_use || c->failed) return;

	if (!c->sent_connect)
	{
		c->sent_connect = 1;
		sock_queue_action(idx + 1, SWF_SOCKET_CONNECT, NULL, 0);
	}

	while (c->cursor < g_script_len)
	{
		SockOp* op = &g_script[c->cursor];
		if (op->kind == OP_SEND)
		{
			sock_queue_action(idx + 1, SWF_SOCKET_DATA, op->bytes, op->len);
			c->cursor++;
		}
		else if (op->kind == OP_DISCONNECT)
		{
			sock_queue_action(idx + 1, SWF_SOCKET_CLOSE, NULL, 0);
			c->cursor++;
		}
		else if (op->kind == OP_RECV)
		{
			if (c->out_head < c->out_count)
			{
				SockMsg* m = &c->out[c->out_head++];
				int ok = (m->len == op->len)
					&& (op->len == 0 || memcmp(m->bytes, op->bytes, op->len) == 0);
				free(m->bytes);
				m->bytes = NULL;
				if (!ok)
				{
					sock_script_fail(c, "received data did not match expected data");
					return;
				}
				c->cursor++;
				continue;
			}
			if (c->dead)
			{
				sock_script_fail(c, "expected client to send data, but the "
				                    "connection was closed instead");
				return;
			}
			return;  // block until the player flushes
		}
		else if (op->kind == OP_WAITDISCONNECT)
		{
			if (c->out_head < c->out_count)
			{
				sock_script_fail(c, "expected client to disconnect, data was "
				                    "sent instead");
				return;
			}
			// Ruffle breaks out of the event loop entirely on disconnect.
			if (c->dead) c->cursor = g_script_len;
			return;
		}
		else
		{
			c->cursor++;
		}
	}
}

// Is any connection still able to produce an event? The AVM1 frame loop uses
// this to stay alive past the last frame, the way it already does for playing
// sounds / active NetStreams: Ruffle's harness runs num_ticks unconditionally,
// ours exits as soon as nothing is asking to run, and an undelivered socket
// action is exactly such a request.
int swf_socket_pending(void)
{
	if (g_action_head < g_action_count) return 1;
	for (int i = 0; i < g_conn_count; i++)
		if (g_conns[i].in_use && !g_conns[i].dead) return 1;
	return 0;
}

static int g_sock_tick_owner;

void swf_socket_tick(int owner)
{
	if (g_conn_count == 0) return;
	// A mixed-AVM movie runs both frame loops; the first one to reach a tick
	// owns the socket cadence so the script cannot advance twice per frame.
	if (g_sock_tick_owner == 0) g_sock_tick_owner = owner;
	if (g_sock_tick_owner != owner) return;

	sock_deliver_actions();
	for (int i = 0; i < g_conn_count; i++) sock_pump_conn(i);
}
