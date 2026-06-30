// n_host_mock.js - standalone host that plays the __swfBridge host role for
// testing (the Archipelago embed would do this for real). Mirrors dj_host_mock.js.
// Configures a level (authored HERE, page-side, so the SWF receives it via
// ExternalInterface - the baked in-SWF fixture is NOT used on this path) and logs
// completion. Override the level via window.__N_CONFIG before this script runs.
(function () {
	// Default level = the grounded "walk right" fixture, authored page-side.
	function buildWalkLevel() {
		var map = "";
		for (var mx = 0; mx < 31; mx++) {
			for (var my = 0; my < 23; my++) {
				map += (my == 14 && mx >= 8 && mx <= 18) ? "1" : "0";
			}
		}
		return map + "|5^276,350!11^310,350,294,350";
	}
	var WALK_DEMO = "28:35791394|35791394|35791394|35791394";

	var cfg = window.__N_CONFIG || {
		levelId: "mock-walk",
		level: buildWalkLevel(),
		demo: WALK_DEMO
	};

	function apply() {
		if (!window.__swfBridge) { setTimeout(apply, 50); return; }
		window.__swfBridge.onExit(function (id) {
			console.log("[host] LEVEL COMPLETE: " + id);
		});
		window.__swfBridge.configure(cfg);
	}
	apply();
})();
