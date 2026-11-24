package {
    // Flash Player image oracle wrapper. See tools/flash-oracle/README.md.
    //
    // Reads capture_config.txt (key=value lines) from its own directory,
    // loads the test SWF with a Loader, counts frames, and at the configured
    // tick draws the stage into a BitmapData and traces it as zlib+base64
    // between "#FLASHCAP BEGIN" / "#FLASHCAP END" lines in flashlog.txt.
    //
    // Tick model (verified, README "Tick alignment"): Ruffle tick k leaves the
    // child at currentFrame k. INIT fires once the child's frame 1 has been
    // constructed and its frame-1 scripts ran (after the wrapper's EXIT_FRAME
    // of that wrapper frame) -> for an AVM2 child that is tick 1, captured
    // right there. An AVM1 child runs frame 1 in the NEXT wrapper frame, so
    // INIT is tick 0. Each later wrapper EXIT_FRAME is the next tick.
    import flash.display.*;
    import flash.events.*;
    import flash.net.*;
    import flash.utils.*;
    import flash.geom.*;
    import flash.system.*;

    public class CaptureWrapper extends Sprite {
        private var cfg:Object = {};
        private var loader:Loader;
        private var tick:int = 0;          // 0 = child not initialised yet
        private var wrapperFrame:int = 0;
        private var captureTicks:Array = [];
        private var captured:int = 0;
        private var avm1:Boolean = false;
        private var started:Boolean = false;
        private var holdNext:Boolean = false;

        public function CaptureWrapper() {
            stage.scaleMode = StageScaleMode.NO_SCALE;
            stage.align = StageAlign.TOP_LEFT;
            var ul:URLLoader = new URLLoader();
            trace("#FLASHCAP START " + Capabilities.version + " " + Capabilities.os + " sandbox=" + Security.sandboxType);
            ul.addEventListener(Event.COMPLETE, onCfg);
            ul.addEventListener(SecurityErrorEvent.SECURITY_ERROR, function(e:*):void { trace("#FLASHCAP ERROR cfg " + e); fscommand("quit"); });
            ul.addEventListener(IOErrorEvent.IO_ERROR, function(e:*):void { trace("#FLASHCAP ERROR cfg " + e); fscommand("quit"); });
            ul.load(new URLRequest("capture_config.txt"));
        }

        private function log(s:String):void {
            if (cfg.verbose == "1") trace("#FLASHCAP " + s);
        }

        private function onCfg(e:Event):void {
            var lines:Array = String(URLLoader(e.target).data).split(/\r?\n/);
            for each (var l:String in lines) {
                var i:int = l.indexOf("=");
                if (i > 0) cfg[l.substr(0, i)] = l.substr(i + 1);
            }
            if (cfg.quality) stage.quality = cfg.quality;
            // The loaded SWF's SetBackgroundColor is ignored by Flash; paint
            // it behind the loader so the SCREEN shows it too (draw() also
            // pre-fills it into the BitmapData).
            graphics.beginFill(uint(cfg.bg));
            graphics.drawRect(0, 0, int(cfg.width), int(cfg.height));
            graphics.endFill();
            for each (var t:String in String(cfg.ticks).split(",")) captureTicks.push(int(t));
            addEventListener(Event.ENTER_FRAME, onEnter);
            addEventListener(Event.EXIT_FRAME, onExit);
            loader = new Loader();
            loader.contentLoaderInfo.addEventListener(Event.INIT, onInit);
            loader.contentLoaderInfo.addEventListener(IOErrorEvent.IO_ERROR, function(e:*):void { trace("#FLASHCAP ERROR load " + e); fscommand("quit"); });
            addChild(loader);
            var ctx:LoaderContext = new LoaderContext(false, ApplicationDomain.currentDomain);
            loader.load(new URLRequest(cfg.swf), ctx);
            log("load " + cfg.swf + " quality=" + stage.quality);
        }

        private function childFrame():String {
            var c:* = null;
            try { c = loader.content; } catch (err:*) {}
            if (c is MovieClip) return "mc:" + MovieClip(c).currentFrame;
            if (c is AVM1Movie) return "avm1";
            return String(c);
        }

        private function onEnter(e:Event):void {
            if (holdNext) {
                holdNext = false;
                trace("#FLASHCAP HOLD");
                var t0:int = getTimer();
                while (getTimer() - t0 < int(cfg.hold_ms || 4000)) {}
                fscommand("quit");
                return;
            }
            wrapperFrame++;
            log("enter wf=" + wrapperFrame + " tick=" + tick + " child=" + childFrame());
        }

        private function onInit(e:Event):void {
            // AVM2 child: frame 1 constructed + scripts ran before INIT -> tick 1.
            // AVM1 child (AVM1Movie): its frame-1 DoAction runs during the NEXT
            // wrapper frame (measured with probes/tick_avm1) -> INIT is tick 0.
            avm1 = loader.contentLoaderInfo.actionScriptVersion < 3;
            tick = avm1 ? 0 : 1;
            started = true;
            log("init wf=" + wrapperFrame + " child=" + childFrame() + " as" + loader.contentLoaderInfo.actionScriptVersion
                + " childrate=" + loader.contentLoaderInfo.frameRate + " stagerate=" + stage.frameRate);
            if (!avm1) afterTick();
        }

        private function afterTick():void {
            if (cfg.marks == "1") trace("#FLASHCAP TICK " + tick);
            if (captureTicks.indexOf(tick) >= 0) {
                if (cfg.image == "0") captured++; else capture(tick);
            }
            if (captured >= captureTicks.length) {
                trace("#FLASHCAP DONE");
                removeEventListener(Event.EXIT_FRAME, onExit);
                if (cfg.hold == "1") {
                    // Screen mode. Lowering stage.frameRate does NOT pin the
                    // frame (measured: the window always showed tick N+1). At
                    // the NEXT wrapper ENTER_FRAME, tick N has been presented
                    // and tick N+1 has not run: block there (see onEnter).
                    holdNext = true;
                } else {
                    fscommand("quit");
                }
            }
        }

        private function onExit(e:Event):void {
            if (!started) return;
            tick++;
            log("exit wf=" + wrapperFrame + " tick=" + tick + " child=" + childFrame());
            afterTick();
        }

        private function lastTick():int {
            var m:int = 0;
            for each (var t:int in captureTicks) if (t > m) m = t;
            return m;
        }

        private function capture(t:int):void {
            var w:int = int(cfg.width), h:int = int(cfg.height);
            var bg:uint = uint(cfg.bg);
            var bd:BitmapData = new BitmapData(w, h, false, bg);
            bd.draw(stage);
            var ba:ByteArray = bd.getPixels(new Rectangle(0, 0, w, h));
            ba.compress();
            var b64:String = b64enc(ba);
            trace("#FLASHCAP BEGIN tick=" + t + " w=" + w + " h=" + h + " len=" + ba.length + " child=" + childFrame());
            for (var i:int = 0; i < b64.length; i += 4096) trace("#FLASHCAP D " + b64.substr(i, 4096));
            trace("#FLASHCAP END tick=" + t);
            captured++;
        }

        private static const CH:String = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
        private static function b64enc(ba:ByteArray):String {
            var out:Array = [];
            var n:int = ba.length;
            ba.position = 0;
            var i:int = 0;
            while (i + 2 < n) {
                var v:int = (ba[i] << 16) | (ba[i + 1] << 8) | ba[i + 2];
                out.push(CH.charAt((v >> 18) & 63) + CH.charAt((v >> 12) & 63) + CH.charAt((v >> 6) & 63) + CH.charAt(v & 63));
                i += 3;
            }
            if (n - i == 1) {
                v = ba[i] << 16;
                out.push(CH.charAt((v >> 18) & 63) + CH.charAt((v >> 12) & 63) + "==");
            } else if (n - i == 2) {
                v = (ba[i] << 16) | (ba[i + 1] << 8);
                out.push(CH.charAt((v >> 18) & 63) + CH.charAt((v >> 12) & 63) + CH.charAt((v >> 6) & 63) + "=");
            }
            return out.join("");
        }
    }
}
