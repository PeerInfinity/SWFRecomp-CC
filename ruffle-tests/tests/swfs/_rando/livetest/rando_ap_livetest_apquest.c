// rando_ap_livetest_apquest.c — native automated round-trip test for the
// Archipelago Rando backend against an APQuest seed-1 server. Sibling of
// rando_ap_livetest.c (ChecksFinder); selected by run_livetest.sh apquest.
//
// APQuest is the canonical example apworld (owned by Archipelago, used as the
// Phase 3 fixture). Unlike the ChecksFinder fixture there is NO starting
// inventory in this seed (Start With One Confetti Cannon: No), and every item
// sits at the player's OWN location, so APCpp filters all grants out of
// received_items (Archipelago.cpp: sending_player == self && location > 0).
// The round-trip is therefore asserted purely via the checked-location signal.
//
// Fixture (verified live against setup_ap_server.py --game apquest --seed 1,
// ids used directly — ap_id_offset = 0):
//   - slot "Player1", game "APQuest", no password, localhost:38281
//   - on connect: 0 items
//   - check location 2  (Top Middle Chest)        -> 2 checked  (grants Sword=2, filtered)
//   - check location 10 (Right Room Enemy Drop)   -> 10 checked (grants Key=1,  filtered)
//
// See SWFRecompDocs/plans/archipelago-phase3-substrate-and-item-application.md.

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
static const char* GAME = "APQuest";
static const char* SLOT = "Player1";

// Location id -> the item it grants (informational; own-location items are
// filtered from received_items by APCpp on the native path).
#define LOC_TOP_MIDDLE_CHEST 2       // grants Sword (2)
#define LOC_ENEMY_DROP       10      // grants Key (1)

static double now_s(void) {
	struct timespec ts;
	clock_gettime(CLOCK_MONOTONIC, &ts);
	return (double)ts.tv_sec + (double)ts.tv_nsec / 1e9;
}

// Send a location and wait (up to TIMEOUT_S) for the server to acknowledge it as
// checked. Returns 1 on success, 0 on timeout.
static int check_location(RandoAP* r, int64_t loc) {
	rando_ap_send_location(r, loc);
	double deadline = now_s() + TIMEOUT_S;
	while (!rando_ap_location_is_checked(r, loc) && now_s() < deadline) {
		sleep_ms(POLL_MS);
	}
	return rando_ap_location_is_checked(r, loc) ? 1 : 0;
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

	// 2) No starting inventory in this seed — informational baseline.
	printf("info: received_items_size on connect = %zu (expected 0; no precollected item)\n",
	       rando_ap_received_items_size(r));

	// 3) Round-trip: check Top Middle Chest -> server marks location 2 checked.
	if (check_location(r, LOC_TOP_MIDDLE_CHEST)) {
		printf("PASS: location %d (Top Middle Chest) checked (send_location round-trip confirmed)\n",
		       LOC_TOP_MIDDLE_CHEST);
	} else {
		printf("FAIL: location %d not checked\n", LOC_TOP_MIDDLE_CHEST);
		failures++;
	}

	// 4) Round-trip: check Right Room Enemy Drop -> server marks location 10 checked.
	if (check_location(r, LOC_ENEMY_DROP)) {
		printf("PASS: location %d (Right Room Enemy Drop) checked (send_location round-trip confirmed)\n",
		       LOC_ENEMY_DROP);
	} else {
		printf("FAIL: location %d not checked\n", LOC_ENEMY_DROP);
		failures++;
	}

	// The items those chests grant (Sword=2, Key=1) are OWN-location items, which
	// APCpp excludes from received_items by design. So received_items stays empty
	// on the native path — informational, not an assertion. (The browser path via
	// archipelago.js does NOT filter, so it sees them; that's run_browser_livetest.)
	printf("info: received_items_size after checks = %zu (own-location items filtered by APCpp)\n",
	       rando_ap_received_items_size(r));
	rando_ap_story_complete(r);  // exercise the call path (no assertion)
	rando_ap_free(r);

	if (failures > 0) {
		printf("\nRESULT: FAIL (%d failed assertion(s))\n", failures);
		return 1;
	}
	printf("\nRESULT: PASS\n");
	return 0;
}
