// n_queue_host.js - standalone host that drives the __swfBridge batch-verify
// QUEUE: configures a list of levels (window.__N_QUEUE, from n_queue_testcases.js)
// and logs each completion. The SWF re-loads each level after completing the
// previous one, all in one page session (the throughput win for verification).
(function () {
	function apply() {
		if (!window.__swfBridge) { setTimeout(apply, 50); return; }
		var q = window.__N_QUEUE || [];
		var seen = [];
		window.__swfBridge.onExit(function (id) {
			seen.push(id);
			console.log("[host] LEVEL COMPLETE: " + id + " (" + seen.length + "/" + q.length + ")");
			if (seen.length === q.length) {
				console.log("[host] ALL QUEUE LEVELS COMPLETE: " + seen.join(","));
			}
		});
		window.__swfBridge.configureQueue(q);
		console.log("[host] queued " + q.length + " levels: "
			+ q.map(function (c) { return c.levelId; }).join(","));
	}
	apply();
})();
