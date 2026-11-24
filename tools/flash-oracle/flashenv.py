"""Shared Flash Player debug-projector plumbing (Linux, Xvfb).

Mirrors ~/CC/ruffle/tests/src/flashplayer/: a throwaway HOME holding mm.cfg,
LC_ALL=C, and max-duration / max-idle timeouts keyed on flashlog.txt mtime.
Adds a FlashPlayerTrust cfg so local Loader loads and BitmapData.draw work.
See tools/flash-oracle/README.md.
"""
import os
import shutil
import struct
import subprocess
import tempfile
import time
import zlib
import lzma

DEFAULT_PLAYER = os.environ.get(
    "FLASH_PLAYER", os.path.expanduser("~/CC/flashplayer/linux/flashplayerdebugger"))


class PlayerEnv:
    def __init__(self, log_warnings=False, trust_paths=()):
        self.root = tempfile.mkdtemp(prefix="flashoracle-")
        cfg = "TraceOutputFileEnable=1\n"
        if log_warnings:
            cfg += "ErrorReportingEnable=1\n"
        cfg += "SuppressDebuggerExceptionDialogs=1\n"
        with open(os.path.join(self.root, "mm.cfg"), "w") as f:
            f.write(cfg)
        self.log_file = os.path.join(self.root, ".macromedia/Flash_Player/Logs/flashlog.txt")
        if trust_paths:
            tdir = os.path.join(self.root, ".macromedia/Flash_Player/#Security/FlashPlayerTrust")
            os.makedirs(tdir, exist_ok=True)
            with open(os.path.join(tdir, "flashoracle.cfg"), "w") as f:
                f.write("\n".join(os.path.abspath(p) for p in trust_paths) + "\n")

    def run(self, swf, max_duration=3.0, max_idle=0.5, player=DEFAULT_PLAYER, cwd=None,
            screen="1280x1024x24", done_marker=None, on_marker=None, triggers=()):
        """Run the projector until exit / timeout / done_marker in flashlog.

        on_marker(display_env) is called once when done_marker appears,
        before the player is killed (used for X screenshots). triggers is a
        list of (marker, fn(display_env)) fired once each when marker first
        appears in flashlog, WITHOUT stopping the player (input injection)."""
        fired = set()
        env = dict(os.environ)
        env["HOME"] = self.root
        env["LC_ALL"] = "C"
        xinfo = os.path.join(self.root, "xinfo")
        # xvfb-run owns the X server + auth; the inner shell reports the
        # DISPLAY/XAUTHORITY it got so on_marker can talk to the same server.
        inner = 'echo "$DISPLAY $XAUTHORITY" > "$0"; exec "$1" "$2"'
        cmd = ["xvfb-run", "-a", "-s", f"-screen 0 {screen}", "sh", "-c", inner, xinfo, player, swf]
        if os.environ.get("FLASH_ORACLE_DISPLAY"):  # run on an existing X display (WSLg / Xvfb)
            env["DISPLAY"] = os.environ["FLASH_ORACLE_DISPLAY"]
            cmd = [player, swf]
        child = subprocess.Popen(cmd, env=env, cwd=cwd, stdout=subprocess.DEVNULL,
                                 stderr=subprocess.DEVNULL, start_new_session=True)
        start = last_activity = time.monotonic()
        last_mtime = None
        killed = None
        while child.poll() is None:
            time.sleep(0.1)
            try:
                mtime = os.stat(self.log_file).st_mtime_ns
            except FileNotFoundError:
                mtime = None
            if mtime != last_mtime:
                last_mtime = mtime
                last_activity = time.monotonic()
            now = time.monotonic()
            for i, (marker, fn) in enumerate(triggers):
                if i not in fired and mtime is not None and marker in self.read_log():
                    fired.add(i)
                    fn(self._display_env(env, xinfo))
                    last_activity = time.monotonic()
            if done_marker and mtime is not None and done_marker in self.read_log():
                killed = "done"
                if on_marker:
                    denv = dict(env)
                    if os.path.exists(xinfo):
                        parts = open(xinfo).read().split()
                        denv["DISPLAY"] = parts[0]
                        if len(parts) > 1:
                            denv["XAUTHORITY"] = parts[1]
                    on_marker(denv)
            elif now - start > max_duration:
                killed = "max_duration"
            elif now - last_activity > max_idle:
                killed = "max_idle"
            if killed:
                try:
                    os.killpg(child.pid, 9)
                except ProcessLookupError:
                    pass
                child.wait()
                break
        self.stop_reason = killed or "exited"
        return self.read_log()

    @staticmethod
    def _display_env(env, xinfo):
        denv = dict(env)
        if os.path.exists(xinfo):
            parts = open(xinfo).read().split()
            denv["DISPLAY"] = parts[0]
            if len(parts) > 1:
                denv["XAUTHORITY"] = parts[1]
        return denv

    def read_log(self):
        try:
            with open(self.log_file, encoding="utf-8", errors="surrogateescape") as f:
                return f.read()
        except FileNotFoundError:
            return ""

    def cleanup(self):
        shutil.rmtree(self.root, ignore_errors=True)


def read_swf_body(path):
    """Return (version, uncompressed bytes after the 8-byte header incl. RECT...)."""
    data = open(path, "rb").read()
    sig, ver = data[:3], data[3]
    if sig == b"FWS":
        body = data[8:]
    elif sig == b"CWS":
        body = zlib.decompress(data[8:])
    elif sig == b"ZWS":
        # ZWS: 4-byte compressed length, 5-byte LZMA props, raw stream
        props = data[12:17]
        filt = lzma._decode_filter_properties(lzma.FILTER_LZMA1, props)
        body = lzma.decompress(data[17:], format=lzma.FORMAT_RAW, filters=[filt])
    else:
        raise ValueError(f"not a SWF: {path}")
    return ver, body


def parse_rect(body):
    nbits = body[0] >> 3
    total = 5 + 4 * nbits
    nbytes = (total + 7) // 8
    bits = int.from_bytes(body[:nbytes], "big")
    vals = []
    for i in range(4):
        shift = nbytes * 8 - 5 - (i + 1) * nbits
        v = (bits >> shift) & ((1 << nbits) - 1)
        if v & (1 << (nbits - 1)):
            v -= 1 << nbits
        vals.append(v)
    return vals, nbytes  # xmin,xmax,ymin,ymax twips


def swf_info(path):
    ver, body = read_swf_body(path)
    (xmin, xmax, ymin, ymax), n = parse_rect(body)
    rate = struct.unpack("<H", body[n:n + 2])[0] / 256.0
    frames = struct.unpack("<H", body[n + 2:n + 4])[0]
    pos = n + 4
    bg = None
    avm2 = False
    while pos + 2 <= len(body):
        code_len = struct.unpack("<H", body[pos:pos + 2])[0]
        code, ln = code_len >> 6, code_len & 0x3F
        pos += 2
        if ln == 0x3F:
            ln = struct.unpack("<I", body[pos:pos + 4])[0]
            pos += 4
        if code == 69 and ln >= 1:  # FileAttributes
            avm2 = bool(body[pos] & 0x08)
        if code == 9 and bg is None:
            bg = (body[pos] << 16) | (body[pos + 1] << 8) | body[pos + 2]
        if code in (1, 0):  # ShowFrame / End: background must be set by then
            break
        pos += ln
    return {"version": ver, "width": (xmax - xmin) / 20.0, "height": (ymax - ymin) / 20.0,
            "rect": (xmin, xmax, ymin, ymax), "rate": rate, "frames": frames,
            "bg": 0xFFFFFF if bg is None else bg, "avm2": avm2}


def encode_rect(xmin, xmax, ymin, ymax):
    vals = [xmin, xmax, ymin, ymax]
    nbits = max(max(abs(v) for v in vals).bit_length() + 1, 2)
    bits = nbits
    acc = nbits
    for v in vals:
        acc = (acc << nbits) | (v & ((1 << nbits) - 1))
        bits += nbits
    bits_total = 5 + 4 * nbits
    pad = (8 - bits_total % 8) % 8
    acc <<= pad
    return acc.to_bytes((bits_total + pad) // 8, "big")


def patch_swf_header(src, dst, rect, rate):
    """Rewrite src SWF's stage RECT and frame rate; write uncompressed dst."""
    ver, body = read_swf_body(src)
    _, n = parse_rect(body)
    rest = body[n:]
    rate_fixed = int(round(rate * 256))
    new_body = encode_rect(*rect) + struct.pack("<H", rate_fixed) + rest[2:]
    out = b"FWS" + bytes([ver]) + struct.pack("<I", 8 + len(new_body)) + new_body
    with open(dst, "wb") as f:
        f.write(out)


# ---------------------------------------------------------------------------
# Windows projector via WSL interop. mm.cfg lives in %USERPROFILE% and the log
# in %APPDATA%\Macromedia\Flash Player\Logs — both per-user, so there is no
# temp-HOME isolation: runs must be sequential. Files are staged under
# C:\flashplayer\work\ (Windows can't read the WSL filesystem by path reliably).
WIN_ROOT = "/mnt/c/flashplayer"
WIN_PLAYER = WIN_ROOT + "/flashplayer_32_sa_debug.exe"
WIN_STARTUP_S = 8.0
WIN_MIN_IDLE_S = 2.5


def _win_env_path(var):
    out = subprocess.run(["cmd.exe", "/c", f"echo %{var}%"], capture_output=True, text=True,
                         cwd="/mnt/c").stdout.strip()
    return subprocess.run(["wslpath", out], capture_output=True, text=True).stdout.strip()


class WinPlayerEnv(PlayerEnv):
    def __init__(self, log_warnings=False, trust_paths=()):
        self.profile = _win_env_path("USERPROFILE")
        self.appdata = _win_env_path("APPDATA")
        cfg = "TraceOutputFileEnable=1\r\n"
        if log_warnings:
            cfg += "ErrorReportingEnable=1\r\n"
        cfg += "SuppressDebuggerExceptionDialogs=1\r\n"
        with open(os.path.join(self.profile, "mm.cfg"), "w", newline="") as f:
            f.write(cfg)
        self.log_file = os.path.join(self.appdata, "Macromedia/Flash Player/Logs/flashlog.txt")
        if os.path.exists(self.log_file):
            os.remove(self.log_file)
        if trust_paths:
            tdir = os.path.join(self.appdata, "Macromedia/Flash Player/#Security/FlashPlayerTrust")
            os.makedirs(tdir, exist_ok=True)
            with open(os.path.join(tdir, "flashoracle.cfg"), "w", newline="") as f:
                f.write("".join(winpath(p) + "\r\n" for p in trust_paths))
        self.root = None

    def run(self, swf, max_duration=3.0, max_idle=0.5, player=WIN_PLAYER, cwd=None,
            screen=None, done_marker=None, on_marker=None, triggers=()):
        # Windows projector timing (measured 2026-11-23): ~4 s from launch to
        # the first flashlog write, then flushes in ~5 KB/s chunks. So the
        # budget gets +WIN_STARTUP_S and idle only counts after the first write.
        child = subprocess.Popen([player, winpath(swf)], cwd=WIN_ROOT,
                                 stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        start = time.monotonic()
        last_activity = None
        last_size = None
        killed = None
        idle = max(max_idle, WIN_MIN_IDLE_S)
        while child.poll() is None:
            time.sleep(0.1)
            try:
                size = os.stat(self.log_file).st_size
            except FileNotFoundError:
                size = None
            if size != last_size:
                last_size, last_activity = size, time.monotonic()
            now = time.monotonic()
            if done_marker and size and done_marker in self.read_log():
                killed = "done"
            elif now - start > max_duration + WIN_STARTUP_S:
                killed = "max_duration"
            elif last_activity is not None and size and now - last_activity > idle:
                killed = "max_idle"
            if killed:
                break
        # Killing the WSL-side interop process does not reliably kill the
        # Windows process; taskkill by image name (only our projector uses it).
        subprocess.run(["taskkill.exe", "/F", "/IM", os.path.basename(player)],
                       capture_output=True, cwd="/mnt/c")
        child.wait()
        self.stop_reason = killed or "exited"
        return self.read_log().replace("\r\n", "\n")

    def cleanup(self):
        pass


def winpath(p):
    return subprocess.run(["wslpath", "-w", os.path.abspath(p)], capture_output=True,
                          text=True).stdout.strip()
