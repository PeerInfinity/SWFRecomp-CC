// avm2_net.c — flash.net transport classes: Socket, NetConnection, Responder,
// NetStream, and the constant-valued AIR/AV stubs.
//
// The URL half of flash.net (URLRequest/URLLoader/URLVariables/navigateToURL)
// lives in avm2_globals.c::register_net and avm2_display.c; this file owns the
// classes that model a *connection*.
//
// Tranche 1 of the net/socket arc (SWFRecompDocs/plans/net-socket-arc.md)
// deliberately implements the surface with NO transport behind it, because
// that is what the corpus grades:
//
//   * `Socket` — every read/write/flush/close on an unconnected socket throws
//     IOError #2002, which is the whole of `socket_errors` (56 lines). The
//     buffers and the socket.json replay that fill them arrive in tranche 2.
//   * `NetConnection` — a two-variant protocol model (Ruffle
//     core/src/net_connection.rs): `connect(null)` opens a "local" connection
//     that reports a fixed set of constants, `connect("http(s)://…")` opens a
//     Flash Remoting connection that reports only its URI, and anything else
//     opens nothing. Every accessor unavailable in the current state throws
//     ArgumentError #2126. `netconnection_properties` grades all three states.
//   * The NetStatusEvent dispatch ORDER around connect/close, including the
//     second, empty-code event Flash emits when an explicit close tears down a
//     Flash Remoting connection — `netconnection_close` grades exactly that.

#include <stdint.h>
#include <string.h>

#include <avm2/avm2_abc.h>
#include <avm2/avm2_class.h>
#include <avm2/avm2_error.h>
#include <avm2/avm2_globals.h>
#include <avm2/avm2_main.h>
#include <avm2/avm2_object.h>
#include <avm2/avm2_value.h>

// ---------------------------------------------------------------------------
// shared helpers
// ---------------------------------------------------------------------------

static Avm2Value net2_str(Avm2Activation* act, const char* s)
{ return avm2_string(avm2_string_from_literal(act->ctx, s)); }

static Avm2Value net2_noop(Avm2Activation* act)
{ (void) act; return avm2_undefined(); }

static Avm2Object* net2_this(Avm2Activation* act)
{
	return (act->this_val.kind == AVM2_VALUE_OBJECT) ? act->this_val.u.obj : NULL;
}

static int net2_arg_bool(Avm2Activation* act, uint32_t i, int dflt)
{
	if (act->argc <= i) return dflt;
	return avm2_coerce_to_boolean(act->args[i]) ? 1 : 0;
}

// ---------------------------------------------------------------------------
// flash.net.Socket
// ---------------------------------------------------------------------------
//
// Ruffle's Socket is an EventDispatcher over a pair of buffers plus a handle
// into the navigator's socket table. With no transport there is never a
// handle, so `connected` is false and every operation that would touch the
// wire raises #2002 — Ruffle's `Socket.as` guards each one with
// `if (!this.connected) throw new IOError(...)`, and Flash renders that as
// "Error: Error #2002: …" because Error's constructor stamps `this.name` from
// *Error*'s prototype, not the subclass's (see avm2_error.c::error_init).

typedef struct Avm2SocketExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	uint8_t connected;
	const Avm2String* endian;           // NULL == "bigEndian"
	uint32_t object_encoding;
	double timeout;
} Avm2SocketExt;

static Avm2Class* g_socket_class;

static Avm2SocketExt* socket_ext(Avm2Activation* act)
{
	Avm2Object* o = net2_this(act);
	return (o != NULL && o->native_ext != NULL) ? (Avm2SocketExt*) o->native_ext : NULL;
}

static _Noreturn void socket_throw_invalid(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.io_error_class,
	                 "Error #2002: Operation attempted on invalid socket.");
}

// Every wire operation funnels through here. Once tranche 2 gives the class a
// real buffer pair this becomes the only guard that stays.
static void socket_require_connected(Avm2Activation* act)
{
	Avm2SocketExt* e = socket_ext(act);
	if (e == NULL || !e->connected) socket_throw_invalid(act->ctx);
}

static Avm2Value socket_init(Avm2Activation* act)
{
	Avm2SocketExt* e = socket_ext(act);
	if (e == NULL) return avm2_undefined();
	e->connected = 0;
	e->endian = NULL;
	e->object_encoding = 3;
	e->timeout = 20000;
	// Socket(host, port) with a non-null host connects immediately. There is
	// no transport yet, so the constructor form behaves like the explicit
	// connect() below: it opens nothing.
	return avm2_undefined();
}

static Avm2Value socket_connect(Avm2Activation* act)
{
	// No transport: the connection never establishes, so nothing changes and
	// no event is dispatched. Tranche 2 replaces this wholesale.
	(void) act;
	return avm2_undefined();
}

static Avm2Value socket_wire_op(Avm2Activation* act)
{
	socket_require_connected(act);
	return avm2_undefined();
}

static Avm2Value socket_get_connected(Avm2Activation* act)
{ Avm2SocketExt* e = socket_ext(act); return avm2_bool(e != NULL && e->connected); }

static Avm2Value socket_get_bytes_available(Avm2Activation* act)
{ (void) act; return avm2_uint_value(0); }

static Avm2Value socket_get_endian(Avm2Activation* act)
{
	Avm2SocketExt* e = socket_ext(act);
	return (e != NULL && e->endian != NULL) ? avm2_string(e->endian)
	                                        : net2_str(act, "bigEndian");
}
static Avm2Value socket_set_endian(Avm2Activation* act)
{
	Avm2SocketExt* e = socket_ext(act);
	if (e != NULL && act->argc > 0)
		e->endian = avm2_coerce_to_string(act->ctx, act->args[0]);
	return avm2_undefined();
}

static Avm2Value socket_get_object_encoding(Avm2Activation* act)
{ Avm2SocketExt* e = socket_ext(act); return avm2_uint_value(e ? e->object_encoding : 3); }
static Avm2Value socket_set_object_encoding(Avm2Activation* act)
{
	Avm2SocketExt* e = socket_ext(act);
	if (e != NULL && act->argc > 0)
		e->object_encoding = avm2_coerce_to_u32(act->ctx, act->args[0]);
	return avm2_undefined();
}

// Socket.timeout clamps to a 250ms floor (Socket.as: `_timeout = value < 250 ?
// 250 : value`), which is what the XMLSocket test's "Timeout clamp" block
// grades.
static Avm2Value socket_get_timeout(Avm2Activation* act)
{ Avm2SocketExt* e = socket_ext(act); return avm2_uint_value(e ? (uint32_t) e->timeout : 20000); }
static Avm2Value socket_set_timeout(Avm2Activation* act)
{
	Avm2SocketExt* e = socket_ext(act);
	if (e != NULL && act->argc > 0)
	{
		uint32_t v = avm2_coerce_to_u32(act->ctx, act->args[0]);
		e->timeout = (v < 250) ? 250 : v;
	}
	return avm2_undefined();
}

static void register_socket(Avm2Context* ctx)
{
	Avm2Class* cls = avm2_builtin_class(ctx, "flash.net", "Socket",
	                                    ctx->builtins.event_dispatcher_class);
	cls->instance_init.fn = socket_init;
	cls->instance_init.debug_name = "Socket";
	cls->native_ext_size = sizeof(Avm2SocketExt);
	g_socket_class = cls;

	avm2_builtin_add_method(ctx, cls, "connect", socket_connect);
	avm2_builtin_add_getter(ctx, cls, "connected", socket_get_connected);
	avm2_builtin_add_getter(ctx, cls, "bytesAvailable", socket_get_bytes_available);
	avm2_builtin_add_getter(ctx, cls, "bytesPending", socket_get_bytes_available);
	avm2_builtin_add_getset(ctx, cls, "endian", socket_get_endian, socket_set_endian);
	avm2_builtin_add_getset(ctx, cls, "objectEncoding",
	                        socket_get_object_encoding, socket_set_object_encoding);
	avm2_builtin_add_getset(ctx, cls, "timeout",
	                        socket_get_timeout, socket_set_timeout);

	// Everything that touches the wire. On an unconnected socket they are all
	// #2002, which is `socket_errors` in its entirety; tranche 2 splits this
	// list into real read/write bodies over the buffer pair.
	static const char* const wire_ops[] = {
		"close", "flush",
		"readBoolean", "readByte", "readBytes", "readDouble", "readFloat",
		"readInt", "readMultiByte", "readObject", "readShort",
		"readUnsignedByte", "readUnsignedInt", "readUnsignedShort", "readUTF",
		"readUTFBytes",
		"writeBoolean", "writeByte", "writeBytes", "writeDouble", "writeFloat",
		"writeInt", "writeMultiByte", "writeObject", "writeShort",
		"writeUnsignedInt", "writeUTF", "writeUTFBytes",
	};
	for (size_t i = 0; i < sizeof(wire_ops) / sizeof(wire_ops[0]); i++)
		avm2_builtin_add_method(ctx, cls, wire_ops[i], socket_wire_op);
}

// ---------------------------------------------------------------------------
// flash.net.NetConnection
// ---------------------------------------------------------------------------

enum
{
	NC_PROTO_NONE = 0,      // never connected, or closed
	NC_PROTO_LOCAL = 1,     // connect(null)
	NC_PROTO_REMOTING = 2,  // connect("http(s)://…")
};

typedef struct Avm2NetConnectionExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	Avm2Value client;                   // defaults to the connection itself
	const Avm2String* uri;              // NULL unless a connection is open
	const Avm2String* proxy_type;       // NULL == "none"
	uint32_t object_encoding;
	uint32_t max_peer_connections;
	uint8_t protocol;
} Avm2NetConnectionExt;

static Avm2Class* g_net_connection_class;
static uint32_t g_nc_default_object_encoding = 3;

static Avm2NetConnectionExt* nc_ext(Avm2Activation* act)
{
	Avm2Object* o = net2_this(act);
	return (o != NULL && o->native_ext != NULL)
		? (Avm2NetConnectionExt*) o->native_ext : NULL;
}

static _Noreturn void nc_throw_2126(Avm2Context* ctx)
{
	avm2_throw_error(ctx, ctx->builtins.argument_error_class,
	                 "Error #2126: NetConnection object must be connected.");
}

// Every accessor that is only meaningful on an open connection. Ruffle models
// this as `handle().and_then(|h| …)` returning None, and every None arm is
// make_error_2126 — except `uri`, which returns null instead (get_uri).
static Avm2NetConnectionExt* nc_require_open(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	if (e == NULL || e->protocol == NC_PROTO_NONE) nc_throw_2126(act->ctx);
	return e;
}

// Only a "local" (connect(null)) connection answers the peer/protocol block;
// a Flash Remoting one reports None for all of it and so throws too.
static Avm2NetConnectionExt* nc_require_local(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_require_open(act);
	if (e->protocol != NC_PROTO_LOCAL) nc_throw_2126(act->ctx);
	return e;
}

static void nc_dispatch_status(Avm2Context* ctx, Avm2Object* self,
                               const char* code)
{
	static const char* const keys[2] = { "code", "level" };
	const char* values[2];
	values[0] = code;
	values[1] = "status";
	Avm2Object* ev = avm2_net_status_event_new(ctx, keys, values, 2);
	if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
}

// [NA, Ruffle net_connection.rs] "I have no idea why, but a NetConnection
// receives a second and nonsensical event on close" — an explicit close() of a
// Flash Remoting connection fires a NetStatusEvent whose code, description and
// details are all the empty string.
static void nc_dispatch_empty_status(Avm2Context* ctx, Avm2Object* self)
{
	static const char* const keys[4] = { "code", "description", "details", "level" };
	static const char* const values[4] = { "", "", "", "status" };
	Avm2Object* ev = avm2_net_status_event_new(ctx, keys, values, 4);
	if (ev != NULL) avm2_dispatch_event(ctx, self, ev);
}

// NetConnections::close. `is_explicit` distinguishes a user close() from the
// implicit teardown that a second connect() performs on the previous handle;
// only the explicit one gets the second event.
static void nc_close_open(Avm2Context* ctx, Avm2Object* self,
                          Avm2NetConnectionExt* e, int is_explicit)
{
	if (e->protocol == NC_PROTO_NONE) return;
	int was_remoting = (e->protocol == NC_PROTO_REMOTING);
	e->protocol = NC_PROTO_NONE;
	e->uri = NULL;
	nc_dispatch_status(ctx, self, "NetConnection.Connect.Closed");
	if (is_explicit && was_remoting) nc_dispatch_empty_status(ctx, self);
}

static int nc_url_is_http(const Avm2String* s)
{
	// Ruffle lowercases the whole URL and then checks both prefixes.
	static const char http[7] = { 'h', 't', 't', 'p', ':', '/', '/' };
	static const char https[8] = { 'h', 't', 't', 'p', 's', ':', '/', '/' };
	for (int pass = 0; pass < 2; pass++)
	{
		const char* pfx = pass ? https : http;
		uint32_t n = pass ? 8u : 7u;
		if (s->len < n) continue;
		uint32_t i = 0;
		for (; i < n; i++)
		{
			char c = s->utf8[i];
			if (c >= 'A' && c <= 'Z') c = (char) (c - 'A' + 'a');
			if (c != pfx[i]) break;
		}
		if (i == n) return 1;
	}
	return 0;
}

static Avm2Value nc_init(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	if (e == NULL) return avm2_undefined();
	e->protocol = NC_PROTO_NONE;
	e->uri = NULL;
	e->proxy_type = NULL;
	e->object_encoding = g_nc_default_object_encoding;
	e->max_peer_connections = 8;
	// NetConnection.as: `private var _client:Object = this;`
	e->client = act->this_val;
	return avm2_undefined();
}

static Avm2Value nc_connect(Avm2Activation* act)
{
	Avm2Context* ctx = act->ctx;
	Avm2Object* self = net2_this(act);
	Avm2NetConnectionExt* e = nc_ext(act);
	if (self == NULL || e == NULL) return avm2_undefined();

	// try_get_string(0): null/undefined/absent all mean "no command".
	const Avm2String* url = NULL;
	if (act->argc > 0 && act->args[0].kind != AVM2_VALUE_NULL
	    && act->args[0].kind != AVM2_VALUE_UNDEFINED)
	{
		url = avm2_coerce_to_string(ctx, act->args[0]);
	}

	if (url == NULL)
	{
		// connect_to_local: the previous handle (if any) is closed
		// NON-explicitly, then the success event fires.
		nc_close_open(ctx, self, e, 0);
		e->protocol = NC_PROTO_LOCAL;
		e->uri = avm2_string_from_literal(ctx, "null");  // yes, the string
		nc_dispatch_status(ctx, self, "NetConnection.Connect.Success");
	}
	else if (nc_url_is_http(url))
	{
		// connect_to_flash_remoting: same non-explicit teardown, and
		// deliberately NO open event.
		nc_close_open(ctx, self, e, 0);
		e->protocol = NC_PROTO_REMOTING;
		e->uri = url;
	}
	// Any other command (rtmp://…, a bare name) is Ruffle's stub arm: no
	// connection is opened and no event fires.
	return avm2_undefined();
}

static Avm2Value nc_close(Avm2Activation* act)
{
	Avm2Object* self = net2_this(act);
	Avm2NetConnectionExt* e = nc_ext(act);
	if (self != NULL && e != NULL) nc_close_open(act->ctx, self, e, 1);
	return avm2_undefined();
}

static Avm2Value nc_get_connected(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	return avm2_bool(e != NULL && e->protocol == NC_PROTO_LOCAL);
}

static Avm2Value nc_get_connected_proxy_type(Avm2Activation* act)
{ nc_require_local(act); return net2_str(act, "none"); }
static Avm2Value nc_get_far_id(Avm2Activation* act)
{ nc_require_local(act); return net2_str(act, ""); }
static Avm2Value nc_get_near_id(Avm2Activation* act)
{ nc_require_local(act); return net2_str(act, ""); }
static Avm2Value nc_get_far_nonce(Avm2Activation* act)
{
	nc_require_local(act);
	return net2_str(act,
		"0000000000000000000000000000000000000000000000000000000000000000");
}
static Avm2Value nc_get_near_nonce(Avm2Activation* act)
{
	nc_require_local(act);
	return net2_str(act,
		"0000000000000000000000000000000000000000000000000000000000000000");
}
static Avm2Value nc_get_protocol(Avm2Activation* act)
{ nc_require_local(act); return net2_str(act, "rtmp"); }
static Avm2Value nc_get_using_tls(Avm2Activation* act)
{ nc_require_local(act); return avm2_bool(0); }

// unconnectedPeerStreams is written in AS3 (NetConnection.as), so it is gated
// on `connected` — i.e. on the LOCAL protocol — not on "a handle exists".
static Avm2Value nc_get_unconnected_peer_streams(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	if (e == NULL || e->protocol != NC_PROTO_LOCAL) nc_throw_2126(act->ctx);
	return avm2_object_value(avm2_array_new(act->ctx, 0));
}

// get_uri is the one accessor whose "no connection" arm is null, not #2126.
static Avm2Value nc_get_uri(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	return (e != NULL && e->uri != NULL) ? avm2_string(e->uri) : avm2_null();
}

static Avm2Value nc_get_client(Avm2Activation* act)
{ Avm2NetConnectionExt* e = nc_ext(act); return e ? e->client : avm2_undefined(); }
static Avm2Value nc_set_client(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	if (e != NULL && act->argc > 0) e->client = act->args[0];
	return avm2_undefined();
}

static Avm2Value nc_get_object_encoding(Avm2Activation* act)
{ Avm2NetConnectionExt* e = nc_ext(act); return avm2_uint_value(e ? e->object_encoding : 3); }
static Avm2Value nc_set_object_encoding(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	if (e != NULL && act->argc > 0)
		e->object_encoding = avm2_coerce_to_u32(act->ctx, act->args[0]);
	return avm2_undefined();
}

static Avm2Value nc_get_max_peer_connections(Avm2Activation* act)
{ Avm2NetConnectionExt* e = nc_ext(act); return avm2_uint_value(e ? e->max_peer_connections : 8); }
static Avm2Value nc_set_max_peer_connections(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	if (e != NULL && act->argc > 0)
		e->max_peer_connections = avm2_coerce_to_u32(act->ctx, act->args[0]);
	return avm2_undefined();
}

static Avm2Value nc_get_proxy_type(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	return (e != NULL && e->proxy_type != NULL) ? avm2_string(e->proxy_type)
	                                            : net2_str(act, "none");
}
static Avm2Value nc_set_proxy_type(Avm2Activation* act)
{
	Avm2NetConnectionExt* e = nc_ext(act);
	if (e != NULL && act->argc > 0)
		e->proxy_type = avm2_coerce_to_string(act->ctx, act->args[0]);
	return avm2_undefined();
}

// NetConnection.call requires an open connection (#2126) and then sends an AMF
// packet, which is tranche 8. Failing the same way Ruffle does on a closed
// connection is free and correct; the send itself is not modelled.
static Avm2Value nc_call(Avm2Activation* act)
{ nc_require_open(act); return avm2_undefined(); }
static Avm2Value nc_add_header(Avm2Activation* act)
{ (void) act; return avm2_undefined(); }

static Avm2Value nc_static_get_default_encoding(Avm2Activation* act)
{ (void) act; return avm2_uint_value(g_nc_default_object_encoding); }
static Avm2Value nc_static_set_default_encoding(Avm2Activation* act)
{
	if (act->argc > 0)
		g_nc_default_object_encoding = avm2_coerce_to_u32(act->ctx, act->args[0]);
	return avm2_undefined();
}

static void register_net_connection(Avm2Context* ctx)
{
	Avm2Class* cls = avm2_builtin_class(ctx, "flash.net", "NetConnection",
	                                    ctx->builtins.event_dispatcher_class);
	cls->instance_init.fn = nc_init;
	cls->instance_init.debug_name = "NetConnection";
	cls->native_ext_size = sizeof(Avm2NetConnectionExt);
	g_net_connection_class = cls;

	avm2_builtin_add_method(ctx, cls, "connect", nc_connect);
	avm2_builtin_add_method(ctx, cls, "close", nc_close);
	avm2_builtin_add_method(ctx, cls, "call", nc_call);
	avm2_builtin_add_method(ctx, cls, "addHeader", nc_add_header);

	avm2_builtin_add_getter(ctx, cls, "connected", nc_get_connected);
	avm2_builtin_add_getter(ctx, cls, "connectedProxyType",
	                        nc_get_connected_proxy_type);
	avm2_builtin_add_getter(ctx, cls, "farID", nc_get_far_id);
	avm2_builtin_add_getter(ctx, cls, "farNonce", nc_get_far_nonce);
	avm2_builtin_add_getter(ctx, cls, "nearID", nc_get_near_id);
	avm2_builtin_add_getter(ctx, cls, "nearNonce", nc_get_near_nonce);
	avm2_builtin_add_getter(ctx, cls, "protocol", nc_get_protocol);
	avm2_builtin_add_getter(ctx, cls, "usingTLS", nc_get_using_tls);
	avm2_builtin_add_getter(ctx, cls, "unconnectedPeerStreams",
	                        nc_get_unconnected_peer_streams);
	avm2_builtin_add_getter(ctx, cls, "uri", nc_get_uri);
	avm2_builtin_add_getset(ctx, cls, "client", nc_get_client, nc_set_client);
	avm2_builtin_add_getset(ctx, cls, "objectEncoding",
	                        nc_get_object_encoding, nc_set_object_encoding);
	avm2_builtin_add_getset(ctx, cls, "maxPeerConnections",
	                        nc_get_max_peer_connections, nc_set_max_peer_connections);
	avm2_builtin_add_getset(ctx, cls, "proxyType",
	                        nc_get_proxy_type, nc_set_proxy_type);
	avm2_builtin_add_static_getset(ctx, cls, "defaultObjectEncoding",
	                               nc_static_get_default_encoding,
	                               nc_static_set_default_encoding);
}

// ---------------------------------------------------------------------------
// flash.net.Responder
// ---------------------------------------------------------------------------
//
// Responder(result:Function, status:Function = null). The callbacks are only
// reachable from NetConnection.call, which does not send yet, so they are
// stored and never invoked. `responder_null_callbacks` grades the one thing
// that is observable today: the class exists and stringifies.

typedef struct Avm2ResponderExt
{
	Avm2Value result_fn;
	Avm2Value status_fn;
} Avm2ResponderExt;

static Avm2Value responder_init(Avm2Activation* act)
{
	Avm2Object* o = net2_this(act);
	if (o == NULL || o->native_ext == NULL) return avm2_undefined();
	Avm2ResponderExt* e = (Avm2ResponderExt*) o->native_ext;
	e->result_fn = act->argc > 0 ? act->args[0] : avm2_null();
	e->status_fn = act->argc > 1 ? act->args[1] : avm2_null();
	return avm2_undefined();
}

// ---------------------------------------------------------------------------
// flash.net.NetStream
// ---------------------------------------------------------------------------
//
// No media pipeline: the corpus tests that need one are dispositioned out of
// this arc (net-socket-arc.md bucket M). What IS graded is the `client`
// property, whose setter rejects every non-object with TypeError #2004 —
// including null and undefined, which is why it cannot be a plain slot.

typedef struct Avm2NetStreamExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	Avm2Value client;                   // defaults to the stream itself
} Avm2NetStreamExt;

static Avm2NetStreamExt* ns_ext(Avm2Activation* act)
{
	Avm2Object* o = net2_this(act);
	return (o != NULL && o->native_ext != NULL) ? (Avm2NetStreamExt*) o->native_ext : NULL;
}

static Avm2Value ns_init(Avm2Activation* act)
{
	Avm2NetStreamExt* e = ns_ext(act);
	if (e == NULL) return avm2_undefined();
	e->client = act->this_val;
	return avm2_undefined();
}

static Avm2Value ns_get_client(Avm2Activation* act)
{ Avm2NetStreamExt* e = ns_ext(act); return e ? e->client : avm2_undefined(); }

static Avm2Value ns_set_client(Avm2Activation* act)
{
	Avm2NetStreamExt* e = ns_ext(act);
	Avm2Value v = act->argc > 0 ? act->args[0] : avm2_undefined();
	if (v.kind != AVM2_VALUE_OBJECT)
	{
		avm2_throw_error(act->ctx, act->ctx->builtins.type_error_class,
		                 "Error #2004: One of the parameters is invalid.");
	}
	if (e != NULL) e->client = v;
	return avm2_undefined();
}

static Avm2Value ns_get_zero(Avm2Activation* act)
{ (void) act; return avm2_number(0); }

// --- flash.net.NetStreamPlayOptions ---------------------------------------
//
// `public var` slots in NetStreamPlayOptions.as, modelled here as accessor
// pairs over an ext (indistinguishable from slots for every read and write a
// script makes) so the three numeric defaults — len -1, offset -1, start -2 —
// can be set in one place.

typedef struct Avm2NpoExt
{
	Avm2EventDispatcherExt dispatcher;  // extends EventDispatcher (MUST be first)
	double len, offset, start;
	Avm2Value old_stream_name, stream_name, transition;
} Avm2NpoExt;

static Avm2NpoExt* npo_ext(Avm2Activation* act)
{
	Avm2Object* o = net2_this(act);
	return (o != NULL && o->native_ext != NULL) ? (Avm2NpoExt*) o->native_ext : NULL;
}

static Avm2Value npo_init(Avm2Activation* act)
{
	Avm2NpoExt* e = npo_ext(act);
	if (e == NULL) return avm2_undefined();
	e->len = -1;
	e->offset = -1;
	e->start = -2;
	e->old_stream_name = avm2_null();
	e->stream_name = avm2_null();
	e->transition = avm2_null();
	return avm2_undefined();
}

#define NPO_NUM_ACCESSORS(field, get_name, set_name)                          \
	static Avm2Value get_name(Avm2Activation* act)                            \
	{ Avm2NpoExt* e = npo_ext(act); return avm2_number(e ? e->field : 0); }    \
	static Avm2Value set_name(Avm2Activation* act)                            \
	{                                                                         \
		Avm2NpoExt* e = npo_ext(act);                                         \
		if (e != NULL && act->argc > 0)                                       \
			e->field = avm2_coerce_to_number(act->ctx, act->args[0]);         \
		return avm2_undefined();                                              \
	}

NPO_NUM_ACCESSORS(len, npo_get_len, npo_set_len)
NPO_NUM_ACCESSORS(offset, npo_get_offset, npo_set_offset)
NPO_NUM_ACCESSORS(start, npo_get_start, npo_set_start)

// The three String vars: an unset one is null, an assigned one coerces (a
// null assignment stays null rather than becoming the string "null").
#define NPO_STR_ACCESSORS(field, get_name, set_name)                          \
	static Avm2Value get_name(Avm2Activation* act)                            \
	{ Avm2NpoExt* e = npo_ext(act); return e ? e->field : avm2_null(); }       \
	static Avm2Value set_name(Avm2Activation* act)                            \
	{                                                                         \
		Avm2NpoExt* e = npo_ext(act);                                         \
		if (e != NULL && act->argc > 0)                                       \
		{                                                                     \
			e->field = (act->args[0].kind == AVM2_VALUE_NULL                  \
			            || act->args[0].kind == AVM2_VALUE_UNDEFINED)         \
				? avm2_null()                                                 \
				: avm2_string(avm2_coerce_to_string(act->ctx, act->args[0])); \
		}                                                                     \
		return avm2_undefined();                                              \
	}

NPO_STR_ACCESSORS(old_stream_name, npo_get_old_name, npo_set_old_name)
NPO_STR_ACCESSORS(stream_name, npo_get_name, npo_set_name)
NPO_STR_ACCESSORS(transition, npo_get_transition, npo_set_transition)

static void register_net_stream(Avm2Context* ctx)
{
	Avm2Class* cls = avm2_builtin_class(ctx, "flash.net", "NetStream",
	                                    ctx->builtins.event_dispatcher_class);
	cls->instance_init.fn = ns_init;
	cls->instance_init.debug_name = "NetStream";
	cls->native_ext_size = sizeof(Avm2NetStreamExt);

	avm2_builtin_add_getset(ctx, cls, "client", ns_get_client, ns_set_client);
	avm2_builtin_add_getter(ctx, cls, "time", ns_get_zero);
	avm2_builtin_add_getter(ctx, cls, "bytesLoaded", ns_get_zero);
	avm2_builtin_add_getter(ctx, cls, "bytesTotal", ns_get_zero);
	avm2_builtin_add_getter(ctx, cls, "currentFPS", ns_get_zero);
	avm2_builtin_add_getter(ctx, cls, "bufferLength", ns_get_zero);
	avm2_builtin_add_method(ctx, cls, "play", net2_noop);
	avm2_builtin_add_method(ctx, cls, "pause", net2_noop);
	avm2_builtin_add_method(ctx, cls, "resume", net2_noop);
	avm2_builtin_add_method(ctx, cls, "togglePause", net2_noop);
	avm2_builtin_add_method(ctx, cls, "seek", net2_noop);
	avm2_builtin_add_method(ctx, cls, "close", net2_noop);
	avm2_builtin_add_method(ctx, cls, "dispose", net2_noop);

	// flash.net.NetStreamPlayOptions — a bag of six defaults with no behaviour
	// (public vars in NetStreamPlayOptions.as; accessor pairs are
	// indistinguishable from slots for every read and write a script makes).
	Avm2Class* npo = avm2_builtin_class(ctx, "flash.net", "NetStreamPlayOptions",
	                                    ctx->builtins.event_dispatcher_class);
	npo->instance_init.fn = npo_init;
	npo->instance_init.debug_name = "NetStreamPlayOptions";
	npo->native_ext_size = sizeof(Avm2NpoExt);
	avm2_builtin_add_getset(ctx, npo, "len", npo_get_len, npo_set_len);
	avm2_builtin_add_getset(ctx, npo, "offset", npo_get_offset, npo_set_offset);
	avm2_builtin_add_getset(ctx, npo, "start", npo_get_start, npo_set_start);
	avm2_builtin_add_getset(ctx, npo, "oldStreamName",
	                        npo_get_old_name, npo_set_old_name);
	avm2_builtin_add_getset(ctx, npo, "streamName",
	                        npo_get_name, npo_set_name);
	avm2_builtin_add_getset(ctx, npo, "transition",
	                        npo_get_transition, npo_set_transition);
}

// ---------------------------------------------------------------------------
// flash.media.AVNetworkingParams
// ---------------------------------------------------------------------------

typedef struct Avm2AvnpExt
{
	uint8_t force_native, read_cookie, cookie_all;
	Avm2Value down_url, query_param;
} Avm2AvnpExt;

static Avm2AvnpExt* avnp_ext(Avm2Activation* act)
{
	Avm2Object* o = net2_this(act);
	return (o != NULL && o->native_ext != NULL) ? (Avm2AvnpExt*) o->native_ext : NULL;
}

static Avm2Value avnp_init(Avm2Activation* act)
{
	Avm2AvnpExt* e = avnp_ext(act);
	if (e == NULL) return avm2_undefined();
	// Only the middle default is true (AVNetworkingParams.as).
	e->force_native = (uint8_t) net2_arg_bool(act, 0, 0);
	e->read_cookie = (uint8_t) net2_arg_bool(act, 1, 1);
	e->cookie_all = (uint8_t) net2_arg_bool(act, 2, 0);
	e->down_url = (act->argc > 3)
		? avm2_string(avm2_coerce_to_string(act->ctx, act->args[3]))
		: avm2_string(avm2_string_from_literal(act->ctx, ""));
	// appendRandomQueryParameter has no initializer, so it reads as null.
	e->query_param = avm2_null();
	return avm2_undefined();
}

#define AVNP_BOOL_ACCESSORS(field, get_name, set_name)                        \
	static Avm2Value get_name(Avm2Activation* act)                            \
	{ Avm2AvnpExt* e = avnp_ext(act); return avm2_bool(e != NULL && e->field); } \
	static Avm2Value set_name(Avm2Activation* act)                            \
	{                                                                         \
		Avm2AvnpExt* e = avnp_ext(act);                                       \
		if (e != NULL && act->argc > 0)                                       \
			e->field = (uint8_t) (avm2_coerce_to_boolean(act->args[0]) ? 1 : 0); \
		return avm2_undefined();                                              \
	}

AVNP_BOOL_ACCESSORS(force_native, avnp_get_force, avnp_set_force)
AVNP_BOOL_ACCESSORS(read_cookie, avnp_get_cookie, avnp_set_cookie)
AVNP_BOOL_ACCESSORS(cookie_all, avnp_get_all_req, avnp_set_all_req)

#define AVNP_STR_ACCESSORS(field, get_name, set_name)                         \
	static Avm2Value get_name(Avm2Activation* act)                            \
	{ Avm2AvnpExt* e = avnp_ext(act); return e ? e->field : avm2_null(); }     \
	static Avm2Value set_name(Avm2Activation* act)                            \
	{                                                                         \
		Avm2AvnpExt* e = avnp_ext(act);                                       \
		if (e != NULL && act->argc > 0)                                       \
		{                                                                     \
			e->field = (act->args[0].kind == AVM2_VALUE_NULL                  \
			            || act->args[0].kind == AVM2_VALUE_UNDEFINED)         \
				? avm2_null()                                                 \
				: avm2_string(avm2_coerce_to_string(act->ctx, act->args[0])); \
		}                                                                     \
		return avm2_undefined();                                              \
	}

AVNP_STR_ACCESSORS(down_url, avnp_get_url, avnp_set_url)
AVNP_STR_ACCESSORS(query_param, avnp_get_qp, avnp_set_qp)

// ---------------------------------------------------------------------------
// registration
// ---------------------------------------------------------------------------

void avm2_register_net_transport(Avm2Context* ctx)
{
	register_socket(ctx);
	register_net_connection(ctx);
	register_net_stream(ctx);

	// flash.net.Responder.
	{
		Avm2Class* cls = avm2_builtin_class(ctx, "flash.net", "Responder",
		                                    ctx->builtins.object_class);
		cls->instance_init.fn = responder_init;
		cls->instance_init.debug_name = "Responder";
		cls->native_ext_size = sizeof(Avm2ResponderExt);
	}

	// flash.net.DatagramSocket — `public class DatagramSocket {}` in AIR.
	// Nothing but its existence is observable (air_datagram_socket traces it).
	avm2_builtin_class(ctx, "flash.net", "DatagramSocket",
	                   ctx->builtins.object_class);

	// flash.media.AVNetworkingParams — three Booleans whose only subtlety is
	// that readSetCookieHeader defaults to TRUE while the other two default
	// to false.
	{
		Avm2Class* cls = avm2_builtin_class(ctx, "flash.media",
		                                    "AVNetworkingParams",
		                                    ctx->builtins.object_class);
		cls->instance_init.fn = avnp_init;
		cls->instance_init.debug_name = "AVNetworkingParams";
		cls->native_ext_size = sizeof(Avm2AvnpExt);
		avm2_builtin_add_getset(ctx, cls, "forceNativeNetworking",
		                        avnp_get_force, avnp_set_force);
		avm2_builtin_add_getset(ctx, cls, "readSetCookieHeader",
		                        avnp_get_cookie, avnp_set_cookie);
		avm2_builtin_add_getset(ctx, cls, "useCookieHeaderForAllRequests",
		                        avnp_get_all_req, avnp_set_all_req);
		avm2_builtin_add_getset(ctx, cls, "networkDownVerificationUrl",
		                        avnp_get_url, avnp_set_url);
		avm2_builtin_add_getset(ctx, cls, "appendRandomQueryParameter",
		                        avnp_get_qp, avnp_set_qp);
	}
}
