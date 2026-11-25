// Direct-mode window pin (tools/flash-oracle/README.md "Direct-mode window pin").
// Root stub with the test's stage RECT and frame rate (header patched per run).
// The projector's GTK drawing area starts at 640x468 and only reaches the SWF size
// a few hundred ms later, so a test run as the projector's FIRST root plays its
// first frames show-all scaled. This stub idles until the harness drops
// __pin_go.txt next to it (Linux: once the X window geometry has settled; Windows:
// after a fixed delay), then replaces _level0 with the test, which then runs as
// the real root at 1:1 from its frame 1. Stage.width/height can't gate this: they
// report the final size from the stub's first frame on.
//
// NO TRACE IN THE TEST'S GLOBALS (s28 flash-oracle-harness): _global and the
// player-global state survive the _level0 replacement, and tests that enumerate
// _global (global_proto_decls*, gnash argstest-v*) printed the old stub's
// `_global.PinStub` and an unqualified `_quality = ...` that landed in _global.
// The old stub's `_quality = ...` also never reached the player: it set
// _global._quality, so test.toml quality was silently ignored.
// So: the class lives in the EXISTING package object `System` (MTASC's class
// prologue probes the package root with GetVariable; a missing name -- a
// top-level class, or a fresh package -- logs "Reference to undeclared
// variable" under ErrorReportingEnable, which reached the test's log), main()
// deletes _global.System.PinStub before anything else, all state lives in main's
// closure, and quality is set as mc._quality (a MovieClip property, not a var).
//
// The stub sets the test.toml render quality (_quality survives the swap into an
// AVM1 root, NOT into an AVM2 root) and carries the test's background colour
// (stamped into its header).
// align=TL (config; set by the harness only for stages narrower than ~296 px)
// survives the replacement: the drawing area is at least ~296 px wide (menubar)
// while the window is only stage-wide, so a centred narrow stage would sit
// outside the visible window. Show-all stays 1:1. The test sees Stage.align TL.
class System.PinStub {
    static function main(mc) {
        delete _global.System.PinStub;
        Stage.scaleMode = "showAll";
        var cfg = new LoadVars();
        var busy = false;
        var done = false;
        cfg.onLoad = function(ok) {
            if (cfg["align"] != undefined) Stage.align = cfg["align"];
            // test.toml with_renderer.quality; player-global, survives the swap.
            if (cfg["quality"] != undefined) mc._quality = cfg["quality"].toUpperCase();
            mc.onEnterFrame = function() {
                if (busy || done) return;
                busy = true;
                var go = new LoadVars();
                go.onLoad = function(ok2) {
                    busy = false;
                    if (ok2 && !done) {
                        done = true;
                        delete mc.onEnterFrame;
                        getURL(cfg["swf"], "_level0");
                    }
                };
                go.load("__pin_go.txt");
            };
        };
        cfg.load("__pin_config.txt");
    }
}
