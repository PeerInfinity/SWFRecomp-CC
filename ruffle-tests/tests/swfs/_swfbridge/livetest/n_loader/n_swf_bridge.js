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
	var _cfg = "";        // current config string returned by __swfConfig
	var _exitCb = null;   // host callback fired on __swfSendExit

	window.__swfConfig = function () { return _cfg; };

	window.__swfSendExit = function (levelId) {
		console.log("[bridge] __swfSendExit " + levelId);
		if (_exitCb) { try { _exitCb(levelId); } catch (e) {} }
		return "";
	};

	window.__swfBridge = {
		configure: function (payload) {
			var id = (payload && payload.levelId) || "host";
			var lev = (payload && payload.level) || "";
			var demo = (payload && payload.demo) || "";
			_cfg = id + "\n" + lev + "\n" + demo;
			console.log("[bridge] configured id=" + id
				+ " levchars=" + lev.length + " demo=" + (demo ? true : false));
		},
		onExit: function (cb) { _exitCb = cb; }
	};
	console.log("[bridge] __swfBridge installed");
})();
