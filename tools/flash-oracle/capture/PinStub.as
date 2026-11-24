// Direct-mode window pin (tools/flash-oracle/README.md "Direct-mode window pin").
// Root stub with the test's stage RECT and frame rate (header patched per run).
// The projector's GTK drawing area starts at 640x468 and only reaches the SWF size
// a few hundred ms later, so a test run as the projector's FIRST root plays its
// first frames show-all scaled. This stub idles until the harness drops
// __pin_go.txt next to it (Linux: once the X window geometry has settled; Windows:
// after a fixed delay), then replaces _level0 with the test, which then runs as
// the real root at 1:1 from its frame 1. Stage.width/height can't gate this: they
// report the final size from the stub's first frame on.
// The stub also sets the test.toml render quality (_quality survives the swap
// into an AVM1 root, NOT into an AVM2 root) and carries the test's background
// colour (stamped into its header).
// align=TL (config; set by the harness only for stages narrower than ~296 px)
// survives the replacement: the drawing area is at least ~296 px wide (menubar)
// while the window is only stage-wide, so a centred narrow stage would sit
// outside the visible window. Show-all stays 1:1. The test sees Stage.align TL.
class PinStub {
    static var cfg:LoadVars;
    static var go:LoadVars;
    static var n:Number = 0;
    static var busy:Boolean = false;
    static function main(mc) {
        Stage.scaleMode = "showAll";
        cfg = new LoadVars();
        cfg.onLoad = function(ok) {
            if (PinStub.cfg["align"] != undefined) Stage.align = PinStub.cfg["align"];
            // test.toml with_renderer.quality; player-global, survives the swap.
            if (PinStub.cfg["quality"] != undefined) _quality = PinStub.cfg["quality"].toUpperCase();
            _root.onEnterFrame = PinStub.tick;
        };
        cfg.load("__pin_config.txt");
    }
    static function tick() {
        n++;
        if (busy) return;
        busy = true;
        go = new LoadVars();
        go.onLoad = function(ok) {
            PinStub.busy = false;
            if (ok && !PinStub.done) {
                PinStub.done = true;
                delete _root.onEnterFrame;
                getURL(PinStub.cfg["swf"], "_level0");
            }
        };
        go.load("__pin_go.txt");
    }
    static var done:Boolean = false;
}
