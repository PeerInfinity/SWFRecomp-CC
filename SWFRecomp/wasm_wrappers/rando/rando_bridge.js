// rando_bridge.js — JS glue between the WASM `Rando` builtin and archipelago.js.
//
// Loaded as an ES module (it imports from the vendored archipelago.js). It
// installs `window.__randoBridge`, the object the EM_JS thunks in
// rando_ap_wasm.c call into. One archipelago.js Client per handle id.
//
// Phase 2, transport only. See
// SWFRecompDocs/plans/archipelago-phase2-wasm-bridge.md.
//
// Connection model (hybrid): `connect(id)` uses the host/port/slot/password
// stashed at construct time by `init(...)` (the AS `new Rando(...)` path). The
// optional HTML connect form calls `connectFromForm(...)` to override those and
// connect — a convenience entry, same chokepoint. An idempotency guard prevents
// a double `login()`.

import { Client, itemsHandlingFlags, clientStatuses } from "./archipelago.js";

const clients = {};   // id -> { client, params, connected, connecting }
let nextId = 1;

function entry(id) {
	return Object.prototype.hasOwnProperty.call(clients, id) ? clients[id] : null;
}

// The single connect chokepoint. Called by connect(id) (AS path) and
// connectFromForm (form path). Idempotent: ignores if already connecting/connected.
function doConnect(e) {
	if (!e || e.connecting || e.connected) {
		return;
	}
	const p = e.params;
	if (!p.host || !p.port || !p.slot) {
		console.error("[rando] connect: missing host/port/slot");
		return;
	}
	e.connecting = true;
	const url = "ws://" + p.host + ":" + parseInt(p.port, 10) + "/";
	const client = new Client();
	e.client = client;
	client.login(url, p.slot, p.game || "", {
		password: p.password || "",
		items: itemsHandlingFlags.all,
		tags: [],
	}).then(function () {
		e.connected = true;
		e.connecting = false;
		console.log("[rando] connected:", p.slot, "@", url);
	}).catch(function (err) {
		e.connecting = false;
		console.error("[rando] login failed:", (err && err.message) || err);
	});
}

window.__randoBridge = {
	// Allocate a handle and stash connection params (no network yet).
	init: function (host, port, game, slot, password) {
		const id = nextId++;
		clients[id] = {
			client: null,
			params: { host: host, port: port, game: game, slot: slot, password: password },
			connected: false,
			connecting: false,
		};
		return id;
	},

	// AS-driven connect (rando.connect()): uses stashed params.
	connect: function (id) {
		doConnect(entry(id));
	},

	isConnected: function (id) {
		const e = entry(id);
		return !!(e && e.connected && e.client && e.client.authenticated);
	},

	receivedItemsSize: function (id) {
		const e = entry(id);
		return (e && e.client) ? e.client.items.received.length : 0;
	},

	// Returns the item id, or -1 if out of range / not ready.
	receivedItem: function (id, idx) {
		const e = entry(id);
		if (!e || !e.client) {
			return -1;
		}
		const recv = e.client.items.received;
		return (idx >= 0 && idx < recv.length) ? recv[idx].id : -1;
	},

	hasItem: function (id, itemId) {
		const e = entry(id);
		if (!e || !e.client) {
			return false;
		}
		return e.client.items.received.some(function (i) { return i.id === itemId; });
	},

	locationIsChecked: function (id, loc) {
		const e = entry(id);
		if (!e || !e.client || !e.client.room) {
			return false;
		}
		return e.client.room.checkedLocations.includes(loc);
	},

	sendLocation: function (id, loc) {
		const e = entry(id);
		if (e && e.client && e.connected) {
			e.client.check(loc);
		}
	},

	storyComplete: function (id) {
		const e = entry(id);
		if (e && e.client && e.connected) {
			e.client.updateStatus(clientStatuses.goal);
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
		doConnect(e);
	},
};

console.log("[rando] bridge ready (archipelago.js loaded)");
