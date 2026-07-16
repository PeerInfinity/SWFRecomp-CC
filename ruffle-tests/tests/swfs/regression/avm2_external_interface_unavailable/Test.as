// AVM2 ExternalInterface — headless/unavailable path (avm2_external.c).
//
// In every non-browser build (native trace, OFFSCREEN_RENDER graphics) and on
// browser pages without the window.__swfBridge shim, ExternalInterface must
// report available == false, objectID == null, and throw the FP Error #2067
// from call/addCallback (the exact semantics the upstream
// avm2/missing_external_interface test pins). marshallExceptions is a plain
// static bool that reads/writes regardless of availability.
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.external.ExternalInterface;

	public class Test extends MovieClip {
		public function Test() {
			trace("available: " + ExternalInterface.available);
			trace("objectID: " + ExternalInterface.objectID);
			trace("marshallExceptions: " + ExternalInterface.marshallExceptions);
			ExternalInterface.marshallExceptions = true;
			trace("marshallExceptions after set: " + ExternalInterface.marshallExceptions);
			ExternalInterface.marshallExceptions = false;

			var r:* = "unset";
			try {
				r = ExternalInterface.call("foo", "a", 1, true);
			} catch (e:Error) {
				trace("call threw: " + e.errorID);
			}
			trace("r: " + r);

			try {
				ExternalInterface.addCallback("cb", function(s:String):String {
					return "x" + s;
				});
			} catch (e2:Error) {
				trace("addCallback threw: " + e2.errorID);
			}
			trace("done");
		}
	}
}
