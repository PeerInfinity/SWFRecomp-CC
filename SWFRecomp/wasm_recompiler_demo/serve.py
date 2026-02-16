#!/usr/bin/env python3
"""Simple HTTP server with COOP/COEP headers for SharedArrayBuffer support.

Serves the docs/ directory so the recompiler demo is at /recompiler/.
"""
import http.server
import os
import sys

PORT = int(sys.argv[1]) if len(sys.argv) > 1 else 8080

# Serve from docs/ directory (two levels up from this script's location in wasm_recompiler_demo/)
DOCS_DIR = os.path.join(os.path.dirname(os.path.abspath(__file__)), "..", "..", "docs")
DOCS_DIR = os.path.normpath(DOCS_DIR)

class CORSHandler(http.server.SimpleHTTPRequestHandler):
    def __init__(self, *args, **kwargs):
        super().__init__(*args, directory=DOCS_DIR, **kwargs)

    def end_headers(self):
        self.send_header("Cross-Origin-Opener-Policy", "same-origin")
        self.send_header("Cross-Origin-Embedder-Policy", "credentialless")
        self.send_header("Cross-Origin-Resource-Policy", "cross-origin")
        super().end_headers()

print(f"Serving {DOCS_DIR} on http://localhost:{PORT}")
print(f"Recompiler demo at http://localhost:{PORT}/recompiler/")
print("COOP/COEP headers enabled (SharedArrayBuffer available)")
http.server.HTTPServer(("", PORT), CORSHandler).serve_forever()
