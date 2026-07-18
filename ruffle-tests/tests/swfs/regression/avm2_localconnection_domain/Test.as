// flash.net.LocalConnection — Robot Wants Fishy and Robot Wants Ice Cream both
// gate their whole boot on `new LocalConnection().domain` as the very first
// instruction of the preloader (an anti-local-copy check: the games bail with a
// blanked stage when the domain is "localhost"). The class was entirely missing,
// so both SWFs died with Error #1065 before Flixel ever started.
//
// `domain` mirrors Ruffle's LocalConnections::get_domain
// (core/src/local_connection.rs): a file:// URL — which is what this test runs
// under — is "localhost"; otherwise it is the exact host of the SWF's URL (AVM2
// uses get_domain, not AVM1's superdomain). There is no IPC layer, so
// connect/send/close are no-ops that must not throw.
//
// Build: see build_swf.sh (mxmlc).
package {
	import flash.display.MovieClip;
	import flash.net.LocalConnection;

	public class Test extends MovieClip {
		public function Test() {
			var lc:LocalConnection = new LocalConnection();

			// The load-bearing property: file:// => "localhost".
			trace("domain: " + lc.domain);
			trace("is string: " + (lc.domain is String));

			// The no-IPC surface must exist and stay silent.
			lc.allowDomain("*");
			lc.allowInsecureDomain("*");
			lc.connect("testConn");
			lc.send("testConn", "someMethod", 1, 2);
			lc.close();
			trace("no-op calls survived");

			trace("done");
		}
	}
}
