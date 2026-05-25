#!/usr/bin/env python3
"""Tiny HTTP server wrapper for serving a docs root (default `docs2/`) to
browser-WASM probes.

Use as a context manager from inspect.py, or stand-alone for manual probing:

    python3 tools/browser-test/serve.py                # docs2/, auto port
    python3 tools/browser-test/serve.py --port 8731    # fixed port
    python3 tools/browser-test/serve.py --root docs    # different root

Picks a free port unless one is given. Binds 127.0.0.1 only (no external
exposure). Logs go to stderr; stdout prints the URL once on startup so
shell wrappers can capture it.
"""
import argparse
import contextlib
import functools
import http.server
import socket
import socketserver
import sys
import threading
from pathlib import Path


REPO_ROOT = Path(__file__).resolve().parents[2]
DEFAULT_ROOT = REPO_ROOT / "docs2"


def _pick_free_port() -> int:
    with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
        s.bind(("127.0.0.1", 0))
        return s.getsockname()[1]


class _QuietHandler(http.server.SimpleHTTPRequestHandler):
    def log_message(self, fmt, *args):
        # Drop default per-request logs; they spam the console during probes.
        pass


@contextlib.contextmanager
def serve(root: Path = DEFAULT_ROOT, port: int = 0):
    """Start an HTTP server in a background thread. Yields (url_base, port).

    On exit, shuts the server down cleanly.
    """
    root = Path(root).resolve()
    if not root.is_dir():
        raise FileNotFoundError(f"docs root does not exist: {root}")
    if port == 0:
        port = _pick_free_port()

    handler = functools.partial(_QuietHandler, directory=str(root))
    httpd = socketserver.ThreadingTCPServer(("127.0.0.1", port), handler)
    httpd.daemon_threads = True
    thread = threading.Thread(target=httpd.serve_forever, daemon=True)
    thread.start()
    try:
        yield f"http://127.0.0.1:{port}", port
    finally:
        httpd.shutdown()
        httpd.server_close()
        thread.join(timeout=2.0)


def main():
    ap = argparse.ArgumentParser(description=__doc__.splitlines()[0])
    ap.add_argument("--root", type=Path, default=DEFAULT_ROOT,
                    help=f"Docs root to serve (default: {DEFAULT_ROOT})")
    ap.add_argument("--port", type=int, default=0,
                    help="Port to bind (default: auto-pick free port)")
    args = ap.parse_args()

    with serve(args.root, args.port) as (url, port):
        print(url, flush=True)
        print(f"Serving {args.root.resolve()} at {url} — Ctrl-C to stop",
              file=sys.stderr, flush=True)
        try:
            threading.Event().wait()
        except KeyboardInterrupt:
            print("\nshutting down", file=sys.stderr)


if __name__ == "__main__":
    main()
