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
import urllib.parse
import zlib
import lzma

# Tall enough that GTK never constrains a 1000-px stage's window (that would
# show-all scale it) and the whole stage stays on screen for grabs.
XVFB_SCREEN = "2048x2600x24"

DEFAULT_PLAYER = os.environ.get(
    "FLASH_PLAYER", os.path.expanduser("~/CC/flashplayer/linux/flashplayerdebugger"))


def toml_fonts(test_dir, toml):
    """The test.toml [fonts.*] files: Ruffle injects them as DEVICE fonts."""
    out = []
    for f in (toml.get("fonts") or {}).values():
        if isinstance(f, dict) and f.get("path"):
            out.append(os.path.join(test_dir, f["path"]))
    return out


class PlayerEnv:
    def __init__(self, log_warnings=False, trust_paths=(), fonts=()):
        """fonts: font files installed into the temp HOME's ~/.fonts, so the
        Linux projector (fontconfig) finds them as device fonts the way Ruffle's
        runner injects a test.toml's [fonts.*]."""
        self.root = tempfile.mkdtemp(prefix="flashoracle-")
        if fonts:
            fdir = os.path.join(self.root, ".fonts")
            os.makedirs(fdir, exist_ok=True)
            for p in fonts:
                shutil.copy(p, fdir)
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
            screen=XVFB_SCREEN, done_marker=None, on_marker=None, triggers=(), pin_gate=None):
        """Run the projector until exit / timeout / done_marker in flashlog.

        pin_gate: a PinGate (direct-mode window pin), polled every tick.

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
            if pin_gate is not None and os.path.exists(xinfo):
                pin_gate.poll(self._display_env(env, xinfo))
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


def patch_swf_header(src, dst, rect, rate, bg=None):
    """Rewrite src SWF's stage RECT and frame rate; write uncompressed dst.
    bg: also drop src's SetBackgroundColor tags and put one with this colour
    first (the pin stub's background survives the _level0 replacement)."""
    ver, body = read_swf_body(src)
    _, n = parse_rect(body)
    rest = body[n:]
    rate_fixed = int(round(rate * 256))
    tags = rest[4:]
    if bg is not None:
        out_tags, pos = [], 0
        while pos + 2 <= len(tags):
            code_len = struct.unpack("<H", tags[pos:pos + 2])[0]
            code, ln, hdr = code_len >> 6, code_len & 0x3F, 2
            if ln == 0x3F:
                ln, hdr = struct.unpack("<I", tags[pos + 2:pos + 6])[0], 6
            if code != 9:
                out_tags.append(tags[pos:pos + hdr + ln])
            pos += hdr + ln
        bgtag = struct.pack("<H", (9 << 6) | 3) + bytes([(bg >> 16) & 255, (bg >> 8) & 255, bg & 255])
        # after a leading FileAttributes tag (it must stay first)
        first = out_tags[:1] if out_tags and (struct.unpack("<H", out_tags[0][:2])[0] >> 6) == 69 else []
        tags = b"".join(first + [bgtag] + out_tags[len(first):])
    new_body = encode_rect(*rect) + struct.pack("<H", rate_fixed) + rest[2:4] + tags
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
            screen=None, done_marker=None, on_marker=None, triggers=(), pin_gate=None):
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
            if pin_gate is not None:
                pin_gate.poll(None)  # no X tree on Windows: time-based
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


# The projector's GTK menubar keeps the drawing area >= ~296 px wide; narrower
# stages are pinned with Stage.align = TL so the stage stays inside the
# (stage-wide) window.
NARROW_STAGE = 296

PIN_STUB = os.path.join(os.path.dirname(os.path.abspath(__file__)), "capture", "PinStub.swf")


def pinned_root(swf, work, url=None, quality=None):
    """Direct-mode window pin. Returns a root stub SWF (release it with a
    PinGate on the same `work`) (in `work`, which must be
    trusted, and must be the test's own directory or a staged copy of it:
    Flash resolves relative URLs against the FIRST root's directory) that replaces _level0 with `swf` only once the projector's drawing
    area is exactly the stage size, so the test runs as the REAL root at 1:1
    from frame 1. Without it the GTK drawing area is 640x468 for the first
    ~0.3-1.5 s (the toplevel shrinks first) and the root is show-all scaled.
    The stub loads `swf` by its basename (same directory); `url` overrides.
    quality: the test.toml with_renderer.quality ("low"/"medium"/"high"/
    "best"); a direct root otherwise renders at the SWF default (high)."""
    info = swf_info(swf)
    stub = os.path.join(work, "__pinstub.swf")
    patch_swf_header(PIN_STUB, stub, info["rect"], info["rate"], bg=info["bg"])
    with open(os.path.join(work, "__pin_config.txt"), "w", newline="") as f:
        f.write(f"width={int(round(info['width']))}&height={int(round(info['height']))}"
                f"&rate={max(info['rate'], 1.0)}"
                + (f"&quality={quality}" if quality else "")
                + ("&align=TL" if info["width"] < NARROW_STAGE else "")
                + f"&swf={urllib.parse.quote(url or os.path.basename(swf), safe=':/')}")
    return stub


XGRAB = os.path.join(os.path.dirname(os.path.abspath(__file__)), "xgrab", "xgrab")


class PinGate:
    """Releases the PinStub (drops __pin_go.txt in its dir) once the projector
    window has settled. Linux: the toplevel's X geometry has left its 640x520
    startup size and held still for `stable` s. Windows (denv None): a fixed
    `win_delay` s after the first poll. Fallback either way: `timeout` s."""

    def __init__(self, work, stable=0.5, timeout=4.0, win_delay=3.0):
        self.go = os.path.join(work, "__pin_go.txt")
        self.stable, self.timeout, self.win_delay = stable, timeout, win_delay
        self.t0 = None
        self.geom = None
        self.since = None
        self.released = None  # "settled WxH" / "timeout" / "delay"
        self.last_poll = 0.0

    def poll(self, denv):
        if self.released:
            return
        now = time.monotonic()
        if self.t0 is None:
            self.t0 = now
        if now - self.last_poll < 0.05:
            return
        self.last_poll = now
        if denv is None:
            if now - self.t0 >= self.win_delay:
                self._release("delay")
            return
        r = subprocess.run([XGRAB], env=denv, capture_output=True, text=True)
        geom = None
        for line in r.stderr.splitlines():
            if "name=Adobe Flash Player" in line:
                geom = line.split("size=")[1].split()[0]
        if geom != self.geom:
            self.geom, self.since = geom, now
        elif geom and geom != "640x520" and now - self.since >= self.stable:
            self._release("settled " + geom)
            return
        if now - self.t0 >= self.timeout:
            self._release("timeout")

    def _release(self, why):
        with open(self.go, "w") as f:
            f.write("go=1")
        self.released = why


def winpath(p):
    return subprocess.run(["wslpath", "-w", os.path.abspath(p)], capture_output=True,
                          text=True).stdout.strip()
