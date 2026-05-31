// rando_ap.c — WASM implementation of the rando_ap.h bridge. Mirrors the native
// rando_ap.cpp, but instead of APCpp it calls into JS (window.__randoBridge in
// rando_bridge.js) via EM_JS thunks, which drive archipelago.js over the
// browser's native WebSocket. APCpp/IXWebSocket are bypassed entirely in the
// browser (IXWebSocket can't link under emscripten).
//
// IMPORTANT: the build copies exactly ONE rando_ap implementation —
//   native build → rando_ap.cpp  (APCpp)
//   wasm build   → rando_ap_wasm.c     (this file)
// They define the same rando_ap.h symbols; never compile both into one binary.
//
// Phase 2, transport only. See
// SWFRecompDocs/plans/archipelago-phase2-wasm-bridge.md.

#include <actionmodern/rando_ap.h>

#if defined(WITH_AP) && defined(__EMSCRIPTEN__)

#include <emscripten.h>
#include <stdlib.h>

// A handle is just the JS-side client id (the JS bridge keeps the real state).
struct RandoAP {
	int id;
};

// --- EM_JS thunks: each calls window.__randoBridge.* (null-tolerant). ----
// Item/location ids are int64 in the C API; JS numbers are doubles (exact to
// 2^53, well beyond any real AP id), so they cross as doubles.

EM_JS(int, js_rando_init, (const char* host, const char* port, const char* game,
                           const char* slot, const char* password), {
	if (!globalThis.__randoBridge) return -1;
	return globalThis.__randoBridge.init(UTF8ToString(host), UTF8ToString(port),
	                                     UTF8ToString(game), UTF8ToString(slot),
	                                     UTF8ToString(password));
});

EM_JS(void, js_rando_connect, (int id), {
	if (globalThis.__randoBridge) globalThis.__randoBridge.connect(id);
});

EM_JS(int, js_rando_is_connected, (int id), {
	return (globalThis.__randoBridge && globalThis.__randoBridge.isConnected(id)) ? 1 : 0;
});

EM_JS(int, js_rando_received_items_size, (int id), {
	return globalThis.__randoBridge ? globalThis.__randoBridge.receivedItemsSize(id) : 0;
});

EM_JS(double, js_rando_received_item, (int id, int idx), {
	return globalThis.__randoBridge ? globalThis.__randoBridge.receivedItem(id, idx) : -1;
});

EM_JS(int, js_rando_has_item, (int id, double item_id), {
	return (globalThis.__randoBridge && globalThis.__randoBridge.hasItem(id, item_id)) ? 1 : 0;
});

EM_JS(int, js_rando_location_is_checked, (int id, double loc), {
	return (globalThis.__randoBridge && globalThis.__randoBridge.locationIsChecked(id, loc)) ? 1 : 0;
});

EM_JS(void, js_rando_send_location, (int id, double loc), {
	if (globalThis.__randoBridge) globalThis.__randoBridge.sendLocation(id, loc);
});

EM_JS(void, js_rando_story_complete, (int id), {
	if (globalThis.__randoBridge) globalThis.__randoBridge.storyComplete(id);
});

// --- rando_ap.h implementation -----------------------------------------------

RandoAP* rando_ap_new(const char* host, const char* port, const char* game,
                      const char* slot, const char* password) {
	int id = js_rando_init(host, port, game, slot, password);
	if (id < 0) {
		return NULL;  // bridge not loaded yet
	}
	RandoAP* r = (RandoAP*)malloc(sizeof(RandoAP));
	if (r == NULL) {
		return NULL;
	}
	r->id = id;
	return r;
}

void rando_ap_free(RandoAP* r) {
	// The JS-side client outlives the C handle (one connection per page); we
	// only free the C wrapper. A js_rando_free could be added if needed.
	if (r != NULL) {
		free(r);
	}
}

void rando_ap_connect(RandoAP* r) {
	if (r != NULL) {
		js_rando_connect(r->id);
	}
}

int rando_ap_is_connected(RandoAP* r) {
	return (r != NULL) ? js_rando_is_connected(r->id) : 0;
}

size_t rando_ap_received_items_size(RandoAP* r) {
	return (r != NULL) ? (size_t)js_rando_received_items_size(r->id) : 0;
}

int64_t rando_ap_received_item(RandoAP* r, size_t idx) {
	return (r != NULL) ? (int64_t)js_rando_received_item(r->id, (int)idx) : -1;
}

int rando_ap_has_item(RandoAP* r, int64_t item_id) {
	return (r != NULL) ? js_rando_has_item(r->id, (double)item_id) : 0;
}

int rando_ap_location_is_checked(RandoAP* r, int64_t location_id) {
	return (r != NULL) ? js_rando_location_is_checked(r->id, (double)location_id) : 0;
}

void rando_ap_send_location(RandoAP* r, int64_t location_id) {
	if (r != NULL) {
		js_rando_send_location(r->id, (double)location_id);
	}
}

void rando_ap_story_complete(RandoAP* r) {
	if (r != NULL) {
		js_rando_story_complete(r->id);
	}
}

#endif  // WITH_AP && __EMSCRIPTEN__
