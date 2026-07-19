package {
	import flash.display.Sprite;
	import flash.display.BitmapData;
	import flash.geom.Rectangle;
	import flash.geom.Point;

	// Regression net for the find→own-class-static lever (fused
	// getlex-ownstatic read + standalone guarded find for static stores),
	// the store-path slot specialization (setproperty_slot / _slot_c with
	// compile-time coerce elision), and the bitmap identity-self-copy skip.
	// See README.md.
	public class Test extends Sprite {
		public function Test() {
			var b:Base = new Base();
			trace("1 " + b.readStatic());
			var s:Sub = new Sub();
			trace("2 " + s.readStatic());
			trace("3 " + Base.counter);
			b.bumpStatic();
			b.bumpStatic();
			trace("4 " + Base.counter);
			var f:Fields = new Fields();
			trace("5 " + f.describe());
			f.numField = 7;
			trace("6 " + f.numField + " " + (f.numField is Number));
			var v:* = 3.7;
			f.intField = v;
			trace("7 " + f.intField);
			f.objField = null;
			trace("8 " + f.objField);
			f.strField = "zz";
			trace("9 " + f.strField);
			var nf:Fields = null;
			try {
				nf.numField = 1;
			} catch (e:Error) {
				trace("10 " + e.errorID);
			}
			trace("11 " + f.constRead());
			bitmapCases();
			trace("done");
		}

		private function bitmapCases():void {
			var bd:BitmapData = new BitmapData(4, 4, true, 0x00000000);
			bd.setPixel32(0, 0, 0xFF112233);
			bd.setPixel32(1, 0, 0xFF445566);
			bd.setPixel32(2, 2, 0xFF778899);
			// Identity self-copy (src rect == dst rect, zero offset): pixels
			// must be unchanged.
			bd.copyPixels(bd, bd.rect, new Point(0, 0));
			trace("12 " + bd.getPixel32(0, 0).toString(16) + " "
				+ bd.getPixel32(1, 0).toString(16) + " "
				+ bd.getPixel32(2, 2).toString(16) + " "
				+ bd.getPixel32(3, 3).toString(16));
			// Disjoint-rect self-copy: plain copy semantics.
			bd.copyPixels(bd, new Rectangle(0, 0, 2, 1), new Point(2, 3));
			trace("13 " + bd.getPixel32(2, 3).toString(16) + " "
				+ bd.getPixel32(3, 3).toString(16));
		}
	}
}

class Base {
	public static var staticName:String = "base-static";
	public static var counter:int = 0;

	// Unqualified own-class-static READ: old-ASC and mxmlc both compile this
	// as findpropstrict(staticName); getproperty(staticName) — the fused
	// getlex-ownstatic site.
	public function readStatic():String {
		return staticName;
	}

	// Unqualified own-class-static STORE: findproperty + setproperty — the
	// standalone guarded find (consumer is not adjacent).
	public function bumpStatic():void {
		counter = counter + 1;
	}
}

// Sub declares an INSTANCE trait with the same name as Base's STATIC. When
// Base.readStatic runs on a Sub instance, the scope walk's first probe
// (`this`) hits the instance trait — the static must NOT win. This is the
// adversarial case for the fused op's guard/fallback (the compile-time pass
// cannot see the shadow; the runtime cache guard must).
class Sub extends Base {
	public var staticName:String = "sub-instance";
}

class Fields {
	public static const CK:int = 40;

	// Class-level initializers run in the constructor (initproperty /
	// setproperty on `this` via find-substituted receivers) — the store-path
	// slot lever's constructor-churn shape.
	public var numField:Number = 1.5;
	public var intField:int = 2;
	public var objField:Object = new Object();
	public var strField:String = "aa";
	public const cf:int = CK + 2;

	public function describe():String {
		return numField + "|" + intField + "|" + (objField != null) + "|" + strField;
	}

	public function constRead():int {
		return cf;
	}
}
