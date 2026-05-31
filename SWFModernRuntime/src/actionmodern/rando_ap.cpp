// rando_ap.cpp — C++ shim translating the pure-POD rando_ap.h API to APCpp's
// C++-typed Archipelago.h API. Compiled with g++ (the rest of the runtime is
// C). Only built/linked when WITH_AP is defined (see build_test.sh).
//
// Design notes:
//  - APCpp is a global-ish library driven by an opaque AP_State* from AP_New().
//    We wrap that pointer in RandoAP so the C side stashes a single handle on
//    the Rando ASObject and the URI-building / bounds-checking stay here.
//  - Item-receipt and location callbacks are OPTIONAL in APCpp (every call site
//    is null-guarded) and the received-items vector is populated by the network
//    thread regardless, so Phase 1 is pure-polling: no callback registered, the
//    AVM1 main thread just reads AP_GetReceivedItemsSize / AP_GetReceivedItem,
//    which lock APCpp's cache_mutex internally (thread-safe).
//  - AP_GetReceivedItem does NOT bounds-check, so rando_ap_received_item guards
//    against OOB here. received_items only grows (we never set the clear
//    callback), so the size-then-get is race-safe.
//
// See SWFRecompDocs/plans/archipelago-randomizer-integration.md.

#include <new>
#include <string>

#include "Archipelago.h"
#include <actionmodern/rando_ap.h>

struct RandoAP {
    AP_State* st;
};

extern "C" {

RandoAP* rando_ap_new(const char* host, const char* port, const char* game,
                      const char* slot, const char* password) {
    RandoAP* r = new (std::nothrow) RandoAP();
    if (r == nullptr) {
        return nullptr;
    }
    r->st = AP_New();
    if (r->st == nullptr) {
        delete r;
        return nullptr;
    }

    std::string uri = (host != nullptr) ? host : "";
    if (port != nullptr && port[0] != '\0') {
        uri += ":";
        uri += port;
    }

    AP_Init(r->st, uri.c_str(),
            (game != nullptr) ? game : "",
            (slot != nullptr) ? slot : "",
            (password != nullptr) ? password : "");
    return r;
}

void rando_ap_free(RandoAP* r) {
    if (r == nullptr) {
        return;
    }
    if (r->st != nullptr) {
        AP_Stop(r->st);
        AP_Free(r->st);
    }
    delete r;
}

void rando_ap_connect(RandoAP* r) {
    if (r != nullptr && r->st != nullptr) {
        AP_Start(r->st);
    }
}

int rando_ap_is_connected(RandoAP* r) {
    return (r != nullptr && r->st != nullptr && AP_IsConnected(r->st)) ? 1 : 0;
}

size_t rando_ap_received_items_size(RandoAP* r) {
    return (r != nullptr && r->st != nullptr) ? AP_GetReceivedItemsSize(r->st) : 0;
}

int64_t rando_ap_received_item(RandoAP* r, size_t idx) {
    if (r == nullptr || r->st == nullptr) {
        return -1;
    }
    if (idx >= AP_GetReceivedItemsSize(r->st)) {
        return -1;
    }
    return AP_GetReceivedItem(r->st, idx);
}

int rando_ap_has_item(RandoAP* r, int64_t item_id) {
    if (r == nullptr || r->st == nullptr) {
        return 0;
    }
    size_t n = AP_GetReceivedItemsSize(r->st);
    for (size_t i = 0; i < n; i++) {
        if (AP_GetReceivedItem(r->st, i) == item_id) {
            return 1;
        }
    }
    return 0;
}

int rando_ap_location_is_checked(RandoAP* r, int64_t location_id) {
    return (r != nullptr && r->st != nullptr && AP_GetLocationIsChecked(r->st, location_id)) ? 1 : 0;
}

void rando_ap_send_location(RandoAP* r, int64_t location_id) {
    if (r != nullptr && r->st != nullptr) {
        AP_SendItem(r->st, location_id);
    }
}

void rando_ap_story_complete(RandoAP* r) {
    if (r != nullptr && r->st != nullptr) {
        AP_StoryComplete(r->st);
    }
}

}  // extern "C"
