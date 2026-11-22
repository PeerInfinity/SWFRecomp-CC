package
{
	import flash.display.Sprite;
	import flash.events.Event;
	import flash.net.SharedObject;

	// SharedObject host-hook contract probe (avm2-sharedobject-host-hook.md).
	// Page 1 (host load answers null): writes data, flush(), clear(),
	// re-getLocal (must hit the cache, no load), keeps an ALIAS of the post-
	// clear data object, then reports it every 10 frames so the driver can
	// see avm2_so_reload repopulate it in place.
	// Page 2 (host load answers page 1's flushed bytes): boot shows them.
	public class Test extends Sprite
	{
		private var so:SharedObject;
		private var alias:Object;
		private var f:int = 0;

		public function Test()
		{
			so = SharedObject.getLocal("sohook", "/");
			trace("[as3] boot " + dump(so.data));
			if (so.data.counter === undefined)
			{
				so.data.counter = 7;
				so.data.list = [1, 2, 3];
				so.data.nested = { a: "x", b: true };
				so.data.name = "seed";
				trace("[as3] flush=" + so.flush());
				so.clear();
				var so2:SharedObject = SharedObject.getLocal("sohook", "/");
				trace("[as3] same=" + (so2 === so) + " afterclear " + dump(so2.data));
				so.data.temp = 99;
			}
			alias = so.data;
			addEventListener(Event.ENTER_FRAME, tick);
		}

		private function tick(e:Event):void
		{
			if (++f % 10 == 0)
				trace("[as3] tick" + f + " aliasIsData=" + (alias === so.data) + " " + dump(alias));
		}

		private static function dump(d:Object):String
		{
			var ks:Array = [];
			for (var k:String in d) ks.push(k);
			ks.sort();
			var s:String = "";
			for each (var key:String in ks)
			{
				var v:* = d[key];
				if (v is Array) v = "[" + v.join(",") + "]";
				else if (v != null && typeof v == "object") v = "{a:" + v.a + ",b:" + v.b + "}";
				s += key + "=" + v + ";";
			}
			return "keys=" + ks.length + " " + s;
		}
	}
}
