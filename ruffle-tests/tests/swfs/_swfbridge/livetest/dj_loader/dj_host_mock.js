// dj_host_mock.js — standalone mock HOST for the dj_loader harness pages
// (test-only; the real embedding host is Archipelago-CC's djReal bridge).
// Mirrors the reference page's dev-harness pattern AND the host's region-move
// behavior: configure() with a region payload, pollItems() on inventory
// change, and on sendExit it FOLLOWS the region's exits table to the target
// region and re-configures — so re-configure region swaps are exercised
// exactly like in the embed.
//
// State carried across swaps (host-owned, like real AP state):
//   * held items (granted once at GRANT_AT_MS, persist forever)
//   * the global collected set: configure() passes the target region's
//     already-collected pickup ids as checkedLocations (revisit dedupe).
//
// Default zero-input scenario: start at region_4_4; grant "Brown platforms"
// at 15s -> brown p9 -> sendExit W -> region_3_4 -> climb (loc_0 fires) ->
// brown p7 -> sendExit E -> back to region_4_4 (loc_0 NOT re-offered) ->
// ping-pong until capture ends.
//
// Load order on a harness page: regions.js, dj_swf_bridge.js, this file,
// then the player (Ruffle or the SWFRecomp WASM Module).

(function () {
	'use strict';
	if (window.__DJ_NO_MOCK) return;

	const regions = window.__DJ_REGIONS;
	if (!regions) { console.error('[mock-host] window.__DJ_REGIONS missing (load regions.js first)'); return; }
	let current = window.__DJ_START_REGION || 'region_4_4';

	// Grant schedule: window.__DJ_GRANTS = [{at: ms, item: name}, ...], or the
	// legacy single-grant knobs.
	const GRANTS = window.__DJ_GRANTS || [{
		at: Number(window.__DJ_GRANT_AT_MS || 15000),
		item: window.__DJ_GRANT_ITEM || 'Brown platforms',
	}];
	const held = [];
	const collected = {}; // region id -> [pickup ids]

	function configureRegion(rid) {
		const r = regions[rid];
		if (!r) { console.error('[mock-host] unknown region ' + rid); return; }
		current = rid;
		console.log('[mock-host] configure(' + rid + '), checked=['
			+ (collected[rid] || []).join(',') + '], items=[' + held.join(',') + ']');
		window.__swfBridge.configure({
			regionId: rid,
			params: r.params,
			checkedLocations: (collected[rid] || []).slice(),
		});
		window.__swfBridge.pollItems(held);
	}

	// Host-injected outward handlers (what the real bridge maps to AP).
	window.__swfBridge = Object.assign(window.__swfBridge || {}, {
		sendLocation(id) {
			console.log('[mock-host] <- sendLocation(' + id + ') in ' + current);
			(collected[current] = collected[current] || []).push(id);
		},
		sendExit(id, side) {
			console.log('[mock-host] <- sendExit(' + id + ', ' + side + ') from ' + current);
			const exit = (regions[current].exits || []).find((e) => e.side === side);
			if (!exit || !exit.targetRegion) {
				console.log('[mock-host] no exit for side ' + side + ' — staying');
				return;
			}
			// Real host moves the AP region then re-publishes configure.
			setTimeout(() => configureRegion(exit.targetRegion), 0);
		},
	});

	function start() {
		configureRegion(current);
		for (const g of GRANTS) {
			setTimeout(function () {
				held.push(g.item);
				console.log('[mock-host] granting "' + g.item + '"');
				window.__swfBridge.pollItems(held);
			}, g.at);
		}
		// Timed region tour (host-driven moves independent of portals), e.g.
		// INJECT_JS='window.__DJ_TOUR=[{at:6000,region:"region_4_3"},...]' —
		// the AP-suggested 3+ region walk for cross-region visual staleness.
		for (const t of (window.__DJ_TOUR || [])) {
			setTimeout(function () { configureRegion(t.region); }, t.at);
		}
	}

	if (document.readyState === 'complete') start();
	else window.addEventListener('load', start);
})();
