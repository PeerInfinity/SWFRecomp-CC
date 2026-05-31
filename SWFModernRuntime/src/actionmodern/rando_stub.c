// rando_stub.c — synthetic, no-network implementation of the rando_ap.h seam.
//
// A third backend alongside rando_ap.cpp (native APCpp) and rando_ap_wasm.c
// (WASM → archipelago.js). Selected at build time via RANDO_STUB=1 instead of
// WITH_AP=1 (both define -DWITH_AP so rando.c references the seam; only the
// backend object differs). Pure C, no APCpp, no thread, no socket — so a test
// runs fully deterministically under the trace harness.
//
// Mirrors the JS StubTransport (SWFRecomp/wasm_wrappers/rando/rando_bridge.js):
// connect() delivers a fixed set of starting items synchronously; a checked
// location can grant an item (a minimal stand-in for a server granting an item
// when a location is checked). This is the Phase 3 Layer-1 deterministic glue
// substrate — see
// SWFRecompDocs/plans/archipelago-phase3-substrate-and-item-application.md §6.
//
// THE FIXTURE LIVES HERE. There is one stub fixture shared by every test built
// with RANDO_STUB=1; tune the arrays below to match the toy test that drives
// it. (If multiple independent fixtures are ever needed, switch to reading
// comma-separated env vars at rando_ap_new time — deliberately not done yet.)

#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>

#include <actionmodern/rando_ap.h>

// ─── Synthetic fixture ───────────────────────────────────────────────────────
// Item/location ids are in the toy's own (APQuest-flavored, offset-free) space;
// the live Slice-2 test layers the real ap_id_offset in via the toy's config.

// Items delivered the moment connect() is called.
static const int64_t STUB_STARTING_ITEMS[] = { 2 };   // 2 = "Sword"

// When a location in STUB_GRANT_LOCATIONS[i] is checked, the item in
// STUB_GRANT_ITEMS[i] is delivered. Parallel arrays, same length.
static const int64_t STUB_GRANT_LOCATIONS[] = { 100 };  // 100 = "Bottom Left Chest"
static const int64_t STUB_GRANT_ITEMS[]     = { 1   };  // 1   = "Key"

#define STUB_STARTING_COUNT ((int)(sizeof(STUB_STARTING_ITEMS) / sizeof(STUB_STARTING_ITEMS[0])))
#define STUB_GRANT_COUNT    ((int)(sizeof(STUB_GRANT_LOCATIONS) / sizeof(STUB_GRANT_LOCATIONS[0])))

// Plenty for a toy; received-items + checked-locations never exceed this.
#define STUB_CAP 64

struct RandoAP {
    int connected;
    int received_count;
    int64_t received[STUB_CAP];   // item ids, in delivery order
    int checked_count;
    int64_t checked[STUB_CAP];    // location ids
};

static void stub_deliver_item(RandoAP* r, int64_t item_id) {
    // Match the JS stub: don't deliver the same id twice.
    for (int i = 0; i < r->received_count; i++) {
        if (r->received[i] == item_id) {
            return;
        }
    }
    if (r->received_count < STUB_CAP) {
        r->received[r->received_count++] = item_id;
    }
}

RandoAP* rando_ap_new(const char* host, const char* port, const char* game,
                      const char* slot, const char* password) {
    (void)host; (void)port; (void)game; (void)slot; (void)password;
    RandoAP* r = (RandoAP*)calloc(1, sizeof(RandoAP));
    return r;  // NULL on OOM, like the real shim
}

void rando_ap_free(RandoAP* r) {
    free(r);
}

void rando_ap_connect(RandoAP* r) {
    if (r == NULL || r->connected) {
        return;
    }
    r->connected = 1;
    for (int i = 0; i < STUB_STARTING_COUNT; i++) {
        stub_deliver_item(r, STUB_STARTING_ITEMS[i]);
    }
}

int rando_ap_is_connected(RandoAP* r) {
    return (r != NULL && r->connected) ? 1 : 0;
}

size_t rando_ap_received_items_size(RandoAP* r) {
    return (r != NULL) ? (size_t)r->received_count : 0;
}

int64_t rando_ap_received_item(RandoAP* r, size_t idx) {
    if (r == NULL || idx >= (size_t)r->received_count) {
        return -1;
    }
    return r->received[idx];
}

int rando_ap_has_item(RandoAP* r, int64_t item_id) {
    if (r == NULL) {
        return 0;
    }
    for (int i = 0; i < r->received_count; i++) {
        if (r->received[i] == item_id) {
            return 1;
        }
    }
    return 0;
}

int rando_ap_location_is_checked(RandoAP* r, int64_t location_id) {
    if (r == NULL) {
        return 0;
    }
    for (int i = 0; i < r->checked_count; i++) {
        if (r->checked[i] == location_id) {
            return 1;
        }
    }
    return 0;
}

void rando_ap_send_location(RandoAP* r, int64_t location_id) {
    if (r == NULL || !r->connected) {
        return;
    }
    if (!rando_ap_location_is_checked(r, location_id)) {
        if (r->checked_count < STUB_CAP) {
            r->checked[r->checked_count++] = location_id;
        }
    }
    // Grant any item mapped to this location (server-grants-on-check stand-in).
    for (int i = 0; i < STUB_GRANT_COUNT; i++) {
        if (STUB_GRANT_LOCATIONS[i] == location_id) {
            stub_deliver_item(r, STUB_GRANT_ITEMS[i]);
        }
    }
}

void rando_ap_story_complete(RandoAP* r) {
    (void)r;  // no-op in the stub
}
