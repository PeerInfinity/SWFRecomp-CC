// rando_panel.js — self-contained Archipelago connect panel for the WASM demo
// viewer. Classic (non-module) script: builds its own DOM and drives the AP
// connection through window.__randoBridge (provided by rando_bridge.js, loaded
// as a module). It is the SINGLE UI source — both docs2/demo.html and
// verify_output.py's deploy_wasm load this rather than duplicating form markup.
//
// Loaded only for WITH_AP demos (the build stages rando_bridge.js +
// archipelago.js + this file next to the demo, and the viewer HEAD-probes
// rando_bridge.js before loading these). See
// SWFRecompDocs/plans/archipelago-phase2-wasm-bridge.md.
//
// The "Connect" button connects via window.__randoBridge.connectFromForm — the
// hybrid path's form chokepoint. ActionScript-driven connect (rando.connect())
// still works independently; this panel is the convenience override.

(function () {
	function el(tag, attrs, text) {
		var e = document.createElement(tag);
		if (attrs) {
			for (var k in attrs) { e.setAttribute(k, attrs[k]); }
		}
		if (text) { e.textContent = text; }
		return e;
	}

	function build() {
		var panel = el("div", { id: "rando-panel", style:
			"margin:10px 0;padding:10px;border:1px solid #4CAF50;border-radius:8px;" +
			"font-family:monospace;display:flex;flex-wrap:wrap;gap:6px;align-items:center;" });

		panel.appendChild(el("strong", { style: "color:#4CAF50;margin-right:6px;" }, "Archipelago"));

		var host = el("input", { id: "rando-host", placeholder: "host", value: "archipelago.gg", size: "14" });
		var port = el("input", { id: "rando-port", placeholder: "port", value: "38281", size: "6" });
		var slot = el("input", { id: "rando-slot", placeholder: "slot", size: "12" });
		var pw   = el("input", { id: "rando-pw", placeholder: "password", type: "password", size: "10" });
		var btn  = el("button", null, "Connect");
		var status = el("span", { id: "rando-status", style: "color:#888;" }, "not connected");

		btn.onclick = function () {
			if (!window.__randoBridge) {
				status.textContent = "bridge not loaded";
				return;
			}
			window.__randoBridge.connectFromForm(host.value, port.value, slot.value, pw.value);
		};

		[host, port, slot, pw, btn, status].forEach(function (e) { panel.appendChild(e); });

		// Insert above the output/log if present, else at the top of <body>.
		var anchor = document.getElementById("output") || document.getElementById("status");
		if (anchor && anchor.parentNode) {
			anchor.parentNode.insertBefore(panel, anchor);
		} else {
			document.body.insertBefore(panel, document.body.firstChild);
		}

		// Poll the bridge for a live status line.
		setInterval(function () {
			if (window.__randoBridge && window.__randoBridge.latestStatus) {
				status.textContent = window.__randoBridge.latestStatus();
			}
		}, 1000);
	}

	if (document.readyState === "loading") {
		document.addEventListener("DOMContentLoaded", build);
	} else {
		build();
	}
})();
