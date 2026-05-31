// rando_ap_livetest.c — native automated round-trip test for the Archipelago
// Rando backend (the rando_ap.h → rando_ap.cpp → APCpp path). Connects to a
// LOCAL AP server and asserts the full item/location round-trip.
//
// This is an INTEGRATION test: it needs a running Archipelago server (the
// ChecksFinder/seed-1 setup from Archipelago-CC). run_livetest.sh starts that
// server, runs this harness, and tears it down. Not part of any deterministic
// trace suite (network timing is non-deterministic).
//
// Expected fixture (verified against Archipelago-CC's setup_ap_server.py
// --game checksfinder --seed 1, server protocol 0.6.x, items_handling=7):
//   - slot "Player1", game "ChecksFinder", no password, localhost:38281
//   - on connect: receive item 80002 (Map Bombs, starting inventory)
//   - check location 81001 (Tile 2) → 81001 appears in checked locations.
//     (The item it grants, 80000 Map Width, is an OWN-location item that APCpp
//     filters out of received_items by design — see the note at assertion 3.)
//
// See SWFRecompDocs/plans/archipelago-randomizer-integration.md.

#include <actionmodern/rando_ap.h>

#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define TIMEOUT_S 20.0
#define POLL_MS 100

static void sleep_ms(long ms) {
	struct timespec ts;
	ts.tv_sec = ms / 1000;
	ts.tv_nsec = (ms % 1000) * 1000000L;
	nanosleep(&ts, NULL);
}

static const char* HOST = "localhost";
static const char* PORT = "38281";
static const char* GAME = "ChecksFinder";
static const char* SLOT = "Player1";

#define ITEM_ON_CONNECT 80002   // Map Bombs (starting inventory)
#define LOCATION_TO_CHECK 81001 // Tile 2
#define ITEM_FROM_CHECK 80000   // Map Width (granted by checking Tile 2)

static double now_s(void) {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

int main(void) {
	int failures = 0;

	RandoAP* r = rando_ap_new(HOST, PORT, GAME, SLOT, "");
	if (r == NULL) {
		printf("FAIL: rando_ap_new returned NULL\n");
		return 1;
	}
	rando_ap_connect(r);

	// 1) Connect within the timeout.
	double deadline = now_s() + TIMEOUT_S;
	while (!rando_ap_is_connected(r) && now_s() < deadline) {
		sleep_ms(POLL_MS);
	}
	if (!rando_ap_is_connected(r)) {
		printf("FAIL: not connected to %s:%s within %.0fs\n", HOST, PORT, TIMEOUT_S);
		rando_ap_free(r);
		return 1;
	}
	printf("PASS: connected to %s:%s as %s/%s\n", HOST, PORT, GAME, SLOT);

	// 2) Starting-inventory item arrives on connect.
	deadline = now_s() + TIMEOUT_S;
	while (!rando_ap_has_item(r, ITEM_ON_CONNECT) && now_s() < deadline) {
		sleep_ms(POLL_MS);
	}
	if (rando_ap_has_item(r, ITEM_ON_CONNECT)) {
		printf("PASS: received starting item %d (Map Bombs)\n", ITEM_ON_CONNECT);
	} else {
		printf("FAIL: starting item %d not received (received_items_size=%zu)\n",
		       ITEM_ON_CONNECT, rando_ap_received_items_size(r));
		failures++;
	}

	// 3) Check a location → server marks it as checked. This is the round-trip
	//    confirmation: our send_location reached the server and was acknowledged.
	rando_ap_send_location(r, LOCATION_TO_CHECK);
	deadline = now_s() + TIMEOUT_S;
	while (!rando_ap_location_is_checked(r, LOCATION_TO_CHECK) && now_s() < deadline) {
		sleep_ms(POLL_MS);
	}
	if (rando_ap_location_is_checked(r, LOCATION_TO_CHECK)) {
		printf("PASS: location %d (Tile 2) checked (send_location round-trip confirmed)\n",
		       LOCATION_TO_CHECK);
	} else {
		printf("FAIL: location %d not checked\n", LOCATION_TO_CHECK);
		failures++;
	}

	// The item that Tile 2 grants (Map Width, %d) is the player's OWN item at
	// their OWN location, which APCpp deliberately excludes from received_items
	// (Archipelago.cpp filters `sending_player == self && location > 0`). So this
	// is INFORMATIONAL, not an assertion — in a real multiworld, items from other
	// players' worlds would appear in received_items.
	if (rando_ap_has_item(r, ITEM_FROM_CHECK)) {
		printf("info: granted item %d present in received_items\n", ITEM_FROM_CHECK);
	} else {
		printf("info: granted item %d not in received_items (own-location item; "
		       "filtered by APCpp as expected)\n", ITEM_FROM_CHECK);
	}
	printf("info: received_items_size=%zu\n", rando_ap_received_items_size(r));
	rando_ap_story_complete(r);  // exercise the call path (no assertion)
	rando_ap_free(r);

	if (failures > 0) {
		printf("\nRESULT: FAIL (%d failed assertion(s))\n", failures);
		return 1;
	}
	printf("\nRESULT: PASS\n");
	return 0;
}
