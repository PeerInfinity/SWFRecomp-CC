// n_swf_bridge.js - page side of the N __swfBridge contract (game side of the
// ExternalInterface link, vendored by an Archipelago-style host). Mirrors DJ's
// swf_bridge.js / dj_swf_bridge.js.
//
// EI-facing window functions (called by the SWF via ExternalInterface.call):
//   __swfConfig()          -> level config string "levelId\nlevStr\ndemoStr"
//                             ("" until the host configures; the SWF polls)
//   __swfSendExit(levelId) -> outward completion event
//
// Host-facing API (window.__swfBridge):
//   configure({levelId, level, demo})  -> set the config the SWF will pull
//   onExit(cb)                         -> cb(levelId) on level completion
//
// Newline is the config separator: it is the only char NOT used by N's level
// strings (tile chars '0'..'Q', and | ! ^ , : in the map/object/demo encodings).
(function () {
	var DONE = "__N_DONE__"; // __swfConfig sentinel: queue exhausted (SWF quits)
	var _queue = [];      // pending config strings (a 1-element queue for configure())
	var _cursor = 0;      // index of the config currently served by __swfConfig
	var _exitCb = null;   // host callback fired on __swfSendExit

	function encodeCfg(payload) {
		var id = (payload && payload.levelId) || "host";
		var lev = (payload && payload.level) || "";
		var demo = (payload && payload.demo) || "";
		return id + "\n" + lev + "\n" + demo;
	}

	// Current config string, or DONE once the queue is exhausted.
	window.__swfConfig = function () {
		return _cursor < _queue.length ? _queue[_cursor] : DONE;
	};

	// The SWF reports a completion: advance to the next queued level. The next
	// __swfConfig poll then returns the next config (or DONE).
	window.__swfSendExit = function (levelId) {
		console.log("[bridge] __swfSendExit " + levelId);
		if (_exitCb) { try { _exitCb(levelId); } catch (e) {} }
		_cursor++;
		if (_cursor < _queue.length) {
			console.log("[bridge] advancing to level " + (_cursor + 1)
				+ "/" + _queue.length);
		} else {
			console.log("[bridge] queue exhausted (" + _queue.length
				+ " levels) -> DONE");
		}
		return "";
	};

	window.__swfBridge = {
		// Single level (back-compat): a 1-element queue.
		configure: function (payload) {
			window.__swfBridge.configureQueue([payload]);
		},
		// Batch: serve these levels one after another, advancing on each exit.
		configureQueue: function (payloads) {
			_queue = (payloads || []).map(encodeCfg);
			_cursor = 0;
			console.log("[bridge] configured queue of " + _queue.length + " level(s)");
		},
		onExit: function (cb) { _exitCb = cb; }
	};
	console.log("[bridge] __swfBridge installed");
})();
