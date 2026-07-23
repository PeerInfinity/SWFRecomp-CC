package {
	import flash.display.Sprite;
	import flash.display.Loader;
	import flash.display.DisplayObject;
	import flash.events.Event;
	import flash.net.URLRequest;

	// Regression for the AGI no-op shell (Elephant Quest EQ-3, gap #3).
	//
	// EQ's New Game handler (MainMenu.clicky, playB case) runs the UNGUARDED
	//   this.shell.agi.hideAGILogin()  ->  this.agi.hideLoginStatus()
	// where AGIStuff.agi is `loader.contentLoaderInfo.content`, assigned only in
	// the Loader's COMPLETE handler (AGIStuff.loadComplete). With no real AGI.swf
	// that content is undefined, so hideLoginStatus() throws #1010 and New Game
	// dies — exactly Ruffle's Failure 1 under a null navigator.
	//
	// Fix (runtime, avm2_display.c `loader_load`): a Loader.load() whose request
	// URL is the ArmorGames AGI helper SWF (…/agi/AGI.swf) seeds a no-op AGI
	// shell as the contentLoaderInfo's `content` and fires a SYNCHRONOUS
	// COMPLETE, so the game's own loadComplete assigns `agi = shell`, addChild's
	// it, and every AG-API method it later calls on the shell is a no-op. We do
	// NOT implement the real ArmorGames API. Reusable: unblocks New Game on any
	// AG/AGI-portal game. This test mirrors AGIStuff's exact sequence.
	public class Test extends Sprite {
		public function Test() {
			var loader:Loader = new Loader();
			loader.contentLoaderInfo.addEventListener(Event.COMPLETE, onComplete);
			// The AGI helper SWF URL triggers the shell (any other URL stays a
			// pure no-op — see avm2_loader_stub). COMPLETE fires synchronously
			// inside load(), so onComplete's traces precede "after load".
			loader.load(new URLRequest("http://cache.armorgames.com/assets/agi/AGI.swf"));
			trace("after load, reached end");
		}

		private function onComplete(e:Event):void {
			trace("COMPLETE fired");
			var agi:* = e.currentTarget.content;
			trace("content non-null: " + (agi != null));
			trace("content is DisplayObject: " + (agi is DisplayObject));
			addChild(agi);                    // AGIStuff.loadComplete addChild's agi
			trace("addChild ok");
			// The unguarded call that would #1010 on undefined — plus the rest of
			// the AG-API surface EQ touches. All must no-op (return undefined).
			agi.init("devKey", "gameKey");
			agi.initAGUI({});
			agi.hideLoginStatus();
			agi.hideAGILogin();
			agi.showScoreboardList([], "Medium");
			agi.showGameShareList();
			trace("agi no-op methods ok, no #1010");
		}
	}
}
