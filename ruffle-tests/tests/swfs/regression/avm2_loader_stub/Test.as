package {
	import flash.display.Sprite;
	import flash.display.Loader;
	import flash.display.LoaderInfo;
	import flash.events.Event;
	import flash.net.URLRequest;

	// Regression for the flash.display.Loader stub that Elephant Quest's
	// AGIStuff constructs during Shell.init (agi.init -> AGIStuff.initAGI).
	// Before the stub existed, `new Loader()` threw #1065 "Loader is not
	// defined", aborting Shell.init BEFORE startIntro() so the intro/title was
	// never reached. Mirrors that exact sequence (AGIStuff.as ctor + initAGI):
	//   new Loader()
	//   loader.contentLoaderInfo.addEventListener(Event.COMPLETE, onComplete)
	//   loader.load(new URLRequest(url))
	// load() is a no-op (no network layer), so COMPLETE never fires and
	// content stays null — the addEventListener is a real no-op registration.
	public class Test extends Sprite {
		public function Test() {
			var loader:Loader = new Loader();
			trace("loader created: " + (loader is Loader));

			var li:LoaderInfo = loader.contentLoaderInfo;
			trace("contentLoaderInfo: " + (li != null));

			li.addEventListener(Event.COMPLETE, onComplete);
			trace("addEventListener ok");

			loader.load(new URLRequest("http://cache.armorgames.com/assets/agi/AGI.swf"));
			trace("load ok, content=" + loader.content);

			trace("no #1065, reached end");
		}

		private function onComplete(e:Event):void {
			// Never fires in the stub (no SWF actually loads).
			trace("COMPLETE fired");
		}
	}
}
