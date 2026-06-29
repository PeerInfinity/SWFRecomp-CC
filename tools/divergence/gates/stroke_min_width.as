class StrokeMin {
	static function drawH(mc:MovieClip, y:Number, w:Number, color:Number):Void {
		mc.lineStyle(w, color, 100);
		mc.moveTo(20, y);
		mc.lineTo(180, y);
	}
	static function main(root:MovieClip):Void {
		// Row 1: hairline lineStyle(0) black  -> Ruffle 1px, SWFRecomp expected invisible
		var a:MovieClip = root.createEmptyMovieClip("a", 1);
		drawH(a, 20, 0, 0x000000);

		// Row 2: lineStyle(2) red at 100% scale -> 2px both
		var b:MovieClip = root.createEmptyMovieClip("b", 2);
		drawH(b, 50, 2, 0xFF0000);

		// Row 3: lineStyle(4) blue drawn at full size then clip scaled to 25%
		//        -> on-screen 1px. Ruffle floors to 1px; SWFRecomp ~0.5px (thin).
		var c:MovieClip = root.createEmptyMovieClip("c", 3);
		c.lineStyle(4, 0x0000FF, 100);
		c.moveTo(80, 320);   // y=320 *0.25 = 80 on screen
		c.lineTo(720, 320);  // x: 20..180 on screen
		c.moveTo(80, 320);
		c._xscale = 25;
		c._yscale = 25;

		// Row 4: lineStyle(2) green drawn at full size then scaled to 25%
		//        -> on-screen 0.5px. Ruffle floors to 1px; SWFRecomp sub-pixel.
		var d:MovieClip = root.createEmptyMovieClip("d", 4);
		d.lineStyle(2, 0x00AA00, 100);
		d.moveTo(80, 440);   // y=440*0.25 = 110 on screen
		d.lineTo(720, 440);
		d._xscale = 25;
		d._yscale = 25;

		root.stop();
	}
}
