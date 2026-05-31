// rando_bridge.js — JS glue between the WASM `Rando` builtin and a pluggable
// AP transport. Installs `window.__randoBridge`, the object the EM_JS thunks in
// rando_ap_wasm.c call into. One transport instance per handle id.
//
// Loaded as an ES module (it imports from the vendored archipelago.js).
//
// PLUGGABLE TRANSPORT (Phase 3 Slice 1). The AS-facing API
// (init/connect/isConnected/hasItem/receivedItem/locationIsChecked/sendLocation/
// storyComplete) is identical across transports; only the wire differs:
//   - WebSocketTransport — archipelago.js Client over a browser WebSocket. The
//     Phase 2 behavior, unchanged. Default. Powers the self-contained demo
//     (Topology A).
//   - StubTransport — synthetic items + checked locations, no network. Powers
//     the deterministic Layer-1 glue test (no server, no browser timing).
//   - HostPostMessageTransport (Topology B substrate) — lands in Slice 3; the
//     factory below is the seam.
// See SWFRecompDocs/plans/archipelago-phase3-substrate-and-item-application.md.
//
// Connection model (hybrid): `connect(id)` uses the host/port/slot/password
// stashed at construct time by `init(...)` (the AS `new Rando(...)` path). The
// optional HTML connect form calls `connectFromForm(...)` to override those and
// connect — a convenience entry, same chokepoint. Each transport's connect() is
// idempotent (no double `login()`).

import { Client, itemsHandlingFlags, clientStatuses } from "./archipelago.js";

// ─── Transports ──────────────────────────────────────────────────────────────
//
// A transport encapsulates one connection's lifecycle + state. All __randoBridge
// data methods delegate to the handle's transport. Contract:
//   connect(params)         initiate (idempotent; no-op if already up/connecting)
//   isConnected()   -> bool
//   isConnecting()  -> bool
//   receivedItemsSize() -> number
//   receivedItem(idx)   -> itemId | -1
//   hasItem(itemId)     -> bool
//   locationIsChecked(loc) -> bool
//   sendLocation(loc)
//   storyComplete()

// archipelago.js Client over a browser WebSocket. Phase 2 behavior, unchanged.
class WebSocketTransport {
	constructor() {
		this.client = null;
		this.connected = false;
		this.connecting = false;
	}

	connect(p) {
		if (this.connecting || this.connected) {
			return;
		}
		if (!p.host || !p.port || !p.slot) {
			console.error("[rando] connect: missing host/port/slot");
			return;
		}
		this.connecting = true;
		const url = "ws://" + p.host + ":" + parseInt(p.port, 10) + "/";
		const client = new Client();
		this.client = client;
		client.login(url, p.slot, p.game || "", {
			password: p.password || "",
			items: itemsHandlingFlags.all,
			tags: [],
		}).then(() => {
			this.connected = true;
			this.connecting = false;
			console.log("[rando] connected:", p.slot, "@", url);
		}).catch((err) => {
			this.connecting = false;
			console.error("[rando] login failed:", (err && err.message) || err);
		});
	}

	isConnected() {
		return !!(this.connected && this.client && this.client.authenticated);
	}

	isConnecting() {
		return this.connecting;
	}

	receivedItemsSize() {
		return this.client ? this.client.items.received.length : 0;
	}

	receivedItem(idx) {
		if (!this.client) {
			return -1;
		}
		const recv = this.client.items.received;
		return (idx >= 0 && idx < recv.length) ? recv[idx].id : -1;
	}

	hasItem(itemId) {
		return !!this.client && this.client.items.received.some((i) => i.id === itemId);
	}

	locationIsChecked(loc) {
		return !!(this.client && this.client.room) && this.client.room.checkedLocations.includes(loc);
	}

	sendLocation(loc) {
		if (this.client && this.connected) {
			this.client.check(loc);
		}
	}

	storyComplete() {
		if (this.client && this.connected) {
			this.client.updateStatus(clientStatuses.goal);
		}
	}
}

// No network. Synthetic items + checked locations from a fixture the test page
// supplies via window.__randoBridgeStubFixture:
//   { startingItems: [id, ...], locationGrants: { [loc]: [id, ...] } }
// connect() delivers startingItems immediately (synchronous, deterministic);
// sendLocation(loc) marks loc checked and delivers locationGrants[loc] — a
// minimal stand-in for a server granting an item when a location is checked.
// Used by the Phase 3 Layer-1 deterministic glue test.
class StubTransport {
	constructor(fixture) {
		this.fixture = fixture || {};
		this.connected = false;
		this.received = [];   // item ids, in delivery order
		this.checked = [];    // location ids
	}

	connect() {
		if (this.connected) {
			return;
		}
		this.connected = true;
		const start = this.fixture.startingItems || [];
		for (let i = 0; i < start.length; i++) {
			this.received.push(start[i]);
		}
		console.log("[rando] stub connected; delivered", this.received.length, "starting item(s)");
	}

	isConnected() {
		return this.connected;
	}

	isConnecting() {
		return false;
	}

	receivedItemsSize() {
		return this.received.length;
	}

	receivedItem(idx) {
		return (idx >= 0 && idx < this.received.length) ? this.received[idx] : -1;
	}

	hasItem(itemId) {
		return this.received.indexOf(itemId) !== -1;
	}

	locationIsChecked(loc) {
		return this.checked.indexOf(loc) !== -1;
	}

	sendLocation(loc) {
		if (!this.connected) {
			return;
		}
		if (this.checked.indexOf(loc) === -1) {
			this.checked.push(loc);
		}
		const grants = (this.fixture.locationGrants || {})[loc] || [];
		for (let i = 0; i < grants.length; i++) {
			if (this.received.indexOf(grants[i]) === -1) {
				this.received.push(grants[i]);
			}
		}
	}

	storyComplete() {
		/* no-op in stub */
	}
}

// Transport selection. Default WebSocket (Topology A standalone). A test page can
// force the stub by setting window.__randoBridgeTransport = "stub" (with an
// optional window.__randoBridgeStubFixture) before this module loads.
// HostPostMessageTransport (Topology B substrate) plugs in here in Slice 3.
function createTransport() {
	const mode = (typeof window !== "undefined" && window.__randoBridgeTransport) || "websocket";
	if (mode === "stub") {
		return new StubTransport(typeof window !== "undefined" ? window.__randoBridgeStubFixture : null);
	}
	return new WebSocketTransport();
}

// ─── Handle registry + AS-facing API ─────────────────────────────────────────

const handles = {};   // id -> { transport, params }
let nextId = 1;

function entry(id) {
	return Object.prototype.hasOwnProperty.call(handles, id) ? handles[id] : null;
}

window.__randoBridge = {
	// Allocate a handle and stash connection params (no network yet).
	init: function (host, port, game, slot, password) {
		const id = nextId++;
		handles[id] = {
			transport: createTransport(),
			params: { host: host, port: port, game: game, slot: slot, password: password },
		};
		return id;
	},

	// AS-driven connect (rando.connect()): uses stashed params.
	connect: function (id) {
		const e = entry(id);
		if (e) {
			e.transport.connect(e.params);
		}
	},

	isConnected: function (id) {
		const e = entry(id);
		return !!(e && e.transport.isConnected());
	},

	receivedItemsSize: function (id) {
		const e = entry(id);
		return e ? e.transport.receivedItemsSize() : 0;
	},

	// Returns the item id, or -1 if out of range / not ready.
	receivedItem: function (id, idx) {
		const e = entry(id);
		return e ? e.transport.receivedItem(idx) : -1;
	},

	hasItem: function (id, itemId) {
		const e = entry(id);
		return !!(e && e.transport.hasItem(itemId));
	},

	locationIsChecked: function (id, loc) {
		const e = entry(id);
		return !!(e && e.transport.locationIsChecked(loc));
	},

	sendLocation: function (id, loc) {
		const e = entry(id);
		if (e) {
			e.transport.sendLocation(loc);
		}
	},

	storyComplete: function (id) {
		const e = entry(id);
		if (e) {
			e.transport.storyComplete();
		}
	},

	// Form-driven connect (convenience override). Connects the most recently
	// created handle (the demo's single Rando), replacing its stashed params.
	connectFromForm: function (host, port, slot, password) {
		const id = nextId - 1;
		const e = entry(id);
		if (!e) {
			console.error("[rando] connectFromForm: no Rando instance yet");
			return;
		}
		e.params.host = host;
		e.params.port = port;
		e.params.slot = slot;
		e.params.password = password;
		e.transport.connect(e.params);
	},

	// Human-readable status of the most recently created handle, for the demo
	// panel's status line. Returns "" before any Rando is constructed.
	latestStatus: function () {
		const id = nextId - 1;
		const e = entry(id);
		if (!e) {
			return "no Rando yet (game hasn't called new Rando())";
		}
		if (e.transport.isConnected()) {
			return "connected — " + e.transport.receivedItemsSize() + " item(s) received";
		}
		if (e.transport.isConnecting()) {
			return "connecting…";
		}
		return "not connected";
	},
};

console.log("[rando] bridge ready (archipelago.js loaded)");
