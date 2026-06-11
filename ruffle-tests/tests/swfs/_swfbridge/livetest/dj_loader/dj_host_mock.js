// dj_host_mock.js — standalone mock HOST for the dj_loader harness pages
// (test-only; the real embedding host is Archipelago-CC's iframe bridge.js).
// Mirrors the reference page's dev-harness pattern: the page is host-naive,
// the mock plays host — configure() with the generated region payload,
// pollItems() on inventory change, and it receives the outward
// sendLocation/sendExit calls.
//
// Scenario (first increment, region_4_4): start with NO items; the hero climbs
// the green column zero-input, collects loc_0 on the way, then bounces in
// place at the column top (the sustained-physics soak). At GRANT_AT_MS we
// grant "Brown platforms" -> p9 appears via pollItems -> the climb continues
// onto it -> sendExit(side_exit_W, W).
//
// Load order on a harness page: region_4_4.js, dj_swf_bridge.js, this file,
// then the player (Ruffle or the SWFRecomp WASM Module).

(function () {
	'use strict';
	if (window.__DJ_NO_MOCK) return;

	const region = window.__DJ_REGION;
	if (!region) { console.error('[mock-host] window.__DJ_REGION missing (load region_*.js first)'); return; }

	const GRANT_AT_MS = Number(window.__DJ_GRANT_AT_MS || 15000);
	const GRANT_ITEM = 'Brown platforms';
	const held = [];

	// Host-injected outward handlers (what the real bridge maps to AP).
	window.__swfBridge = Object.assign(window.__swfBridge || {}, {
		sendLocation(id) { console.log('[mock-host] <- sendLocation(' + id + ')'); },
		sendExit(id, side) { console.log('[mock-host] <- sendExit(' + id + ', ' + side + ')'); },
	});

	function start() {
		console.log('[mock-host] configure(' + region.regionId + '), items=[]');
		window.__swfBridge.configure(region);
		window.__swfBridge.pollItems(held);
		setTimeout(function () {
			held.push(GRANT_ITEM);
			console.log('[mock-host] granting "' + GRANT_ITEM + '"');
			window.__swfBridge.pollItems(held);
		}, GRANT_AT_MS);
	}

	if (document.readyState === 'complete') start();
	else window.addEventListener('load', start);
})();
