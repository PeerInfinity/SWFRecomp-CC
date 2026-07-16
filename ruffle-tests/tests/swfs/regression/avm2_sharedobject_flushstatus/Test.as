// flash.net.SharedObjectFlushStatus — the constants class FlxSave (Flixel)
// compares SharedObject.flush()'s return value against:
//   return status == SharedObjectFlushStatus.FLUSHED;
// Robot Wants Kitty aborted its FlxGame boot with Error #1065 when the class
// was missing (avm2_amf.c). flush() on our network-less SharedObject always
// reports "flushed".
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.net.SharedObject;
	import flash.net.SharedObjectFlushStatus;

	public class Test extends MovieClip {
		public function Test() {
			trace("FLUSHED: " + SharedObjectFlushStatus.FLUSHED);
			trace("PENDING: " + SharedObjectFlushStatus.PENDING);

			var so:SharedObject = SharedObject.getLocal("flushtest");
			so.data.value = 42;
			var status:Object = so.flush();
			trace("flush == FLUSHED: " + (status == SharedObjectFlushStatus.FLUSHED));
			trace("done");
		}
	}
}
